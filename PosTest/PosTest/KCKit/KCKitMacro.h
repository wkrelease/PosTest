//
//  KCKitMacro.h
//  KCKit
//
//  Created by king on 16/2/26.
//  Copyright © 2016年 KC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <sys/time.h>
#import <pthread.h>

#import "KCAssertDefine.h"

#ifndef KCKitMacro_h
#define KCKitMacro_h

#ifdef __cplusplus
#define KC_EXTERN_C_BEGIN extern "C"{
#define KC_EXTERN_C_END }
#else
#define KC_EXTERN_C_BEGIN
#define KC_EXTERN_C_END
#endif

KC_EXTERN_C_BEGIN

/**
 *return the clamped value
 */
#ifndef KC_CLAMP
#define KC_CLAMP(_x_, _low_, _high_)  (((_x_) > (_high_)) ? (_high_) : (((_x_) < (_low_)) ? (_low_) : (_x_)))
#endif

/**
 *swap two value
 */
#ifndef KC_SWAP 
#define KC_SWAP(_a_, _b_)  do { __typeof__(_a_) _tmp_ = (_a_); (_a_) = (_b_); (_b_) = _tmp_; } while (0)
#endif

#define KCAssertNil(condition,description,...) NSAssert(!(condition), (description), ##__VA_ARGS__)
#define KCCAssertNil(condition, description, ...) NSCAssert(!(condition), (description), ##__VA_ARGS__)

#define KCAssertNotNil(condition,description,...) NSAssert((condition), (description), ##__VA_ARGS__)
#define KCCAssertNotNil(condition, description, ...) NSCAssert((condition), (description), ##__VA_ARGS__)

#define KCAssertMainThread() NSAssert([NSThread isMainThread], MUST_MAIN_THREAD)
#define KCCAssertMainThread() NSCAssert([NSThread isMainThread],MUST_MAIN_THREAD)

#ifndef KCSYNTH_DUMMY_CLASS
#define KCSYNTH_DUMMY_CLASS(_name_)\
@interface KCSYNTH_DUMMY_CLASS_ ## _name_ : NSObject @end \
@implementation KCSYNTH_DUMMY_CLASS_ ## _name_ @end
#endif

/**
 Synthsize a dynamic object property in @implementation scope.
 It allows us to add custom properties to existing classes in categories.
 
 @param association  ASSIGN / RETAIN / COPY / RETAIN_NONATOMIC / COPY_NONATOMIC
 @warning #import <objc/runtime.h>
 *******************************************************************************
 Example:
 @interface NSObject (MyAdd)
 @property (nonatomic, retain) UIColor *myColor;
 @end
 
 #import <objc/runtime.h>
 @implementation NSObject (MyAdd)
 KCSYNTH_DYNAMIC_PROPERTY_OBJECT(myColor, setMyColor, RETAIN, UIColor *)
 @end
 */

#ifndef KCSYNTH_DYNAMIC_PROPERTY_OBJECT
#define KCSYNTH_DYNAMIC_PROPERTY_OBJECT(_getter_,_setter_,_association_,_type_)\
- (void)_setter_ : (_type_)object { \
[self willChangeValueForKey:@#_getter_]; \
objc_setAssociatedObject(self, _cmd, object, OBJC_ASSOCIATION_ ## _association_); \
[self didChangeValueForKey:@#_getter_]; \
} \
- (_type_)_getter_ { \
return objc_getAssociatedObject(self, @selector(_setter_:)); \
}
#endif




/**
 Synthsize a dynamic c type property in @implementation scope.
 It allows us to add custom properties to existing classes in categories.
 
 @warning #import <objc/runtime.h>
 *******************************************************************************
 Example:
 @interface NSObject (MyAdd)
 @property (nonatomic, retain) CGPoint myPoint;
 @end
 
 #import <objc/runtime.h>
 @implementation NSObject (MyAdd)
 KCSYNTH_DYNAMIC_PROPERTY_CTYPE(myPoint, setMyPoint, CGPoint)
 @end
 */
#ifndef KCSYNTH_DYNAMIC_PROPERTY_CTYPE
#define KCSYNTH_DYNAMIC_PROPERTY_CTYPE(_getter_, _setter_, _type_) \
- (void)_setter_ : (_type_)object { \
[self willChangeValueForKey:@#_getter_]; \
NSValue *value = [NSValue value:&object withObjCType:@encode(_type_)]; \
objc_setAssociatedObject(self, _cmd, value, OBJC_ASSOCIATION_RETAIN); \
[self didChangeValueForKey:@#_getter_]; \
} \
- (type)_getter_ { \
_type_ cValue = { 0 }; \
NSValue *value = objc_getAssociatedObject(self, @selector(_setter_:)); \
[value getValue:&cValue]; \
return cValue; \
}
#endif




/**
 Synthsize a weak or strong reference.
 
 Example:
 @weakify(self)
 [self doSomething^{
 @strongify(self)
 if (!self) return;
 ...
 }];
 
 */
#ifndef weakify
#if DEBUG
#if __has_feature(objc_arc)
#define weakify(object) autoreleasepool{} __weak __typeof__(object) weak##_##object = object;
#else
#define weakify(object) autoreleasepool{} __block __typeof__(object) block##_##object = object;
#endif
#else
#if __has_feature(objc_arc)
#define weakify(object) try{} @finally{} {} __weak __typeof__(object) weak##_##object = object;
#else
#define weakify(object) try{} @finally{} {} __block __typeof__(object) block##_##object = object;
#endif
#endif
#endif

#ifndef strongify
#if DEBUG
#if __has_feature(objc_arc)
#define strongify(object) autoreleasepool{} __typeof__(object) object = weak##_##object;
#else
#define strongify(object) autoreleasepool{} __typeof__(object) object = block##_##object;
#endif
#else
#if __has_feature(objc_arc)
#define strongify(object) try{} @finally{} __typeof__(object) object = weak##_##object;
#else
#define strongify(object) try{} @finally{} __typeof__(object) object = block##_##object;
#endif
#endif
#endif


/**
 Convert CFRange to NSRange
 @param range CFRange @return NSRange
 */
static inline NSRange KCNSRangeFromCFRange(CFRange range){
    return NSMakeRange(range.location, range.length);
}
/**
 Convert NSRange to CFRange
 @param range NSRange @return CFRange
 */
static inline CFRange KCCFRangeFromNSRange(NSRange range) {
    return CFRangeMake(range.location, range.length);
}
/**
 Same as CFAutorelease(), compatible for iOS6
 @param arg CFObject @return same as input
 */
static inline CFTypeRef KCCFAutorelease(CFTypeRef CF_RELEASES_ARGUMENT arg) {
    if (((long)CFAutorelease + 1) != 1) {
        return CFAutorelease(arg);
    } else {
        id __autoreleasing obj = CFBridgingRelease(arg);
        return (__bridge CFTypeRef)obj;
    }
}
 
static inline void KCBenchmark(void (^block)(void),void (^complete)(double ms)){
    // <QuartzCore/QuartzCore.h> version
    /*
     extern double CACurrentMediaTime (void);
     double begin, end, ms;
     begin = CACurrentMediaTime();
     block();
     end = CACurrentMediaTime();
     ms = (end - begin) * 1000.0;
     complete(ms);
     */
    
    struct timeval t0,t1;
    gettimeofday(&t0, NULL);
    block();
    gettimeofday(&t1, NULL);
    double ms = (double)(t1.tv_sec - t0.tv_sec) * 1e3 + (double)(t1.tv_usec - t0.tv_usec) * 1e-3;
    complete(ms);
    
}

/**
 Get compile timestamp.
 @return NSData
 */
static inline NSDate *KCCompileTime(){
    
    NSString *timeStr = [NSString stringWithFormat:@"%s %s",__DATE__,__TIME__];
    NSLocale *locale = [[NSLocale alloc]initWithLocaleIdentifier:@"en_US"];
    NSDateFormatter *formatter = [[NSDateFormatter alloc]init];
    [formatter setDateFormat:@"MM-dd-yyyy HH:mm:ss"];
    [formatter setLocale:locale];
    return [formatter dateFromString:timeStr];
    
}

/**
 Returns a dispatch_time delay from now.
 */
static inline dispatch_time_t dispatch_time_delay(NSTimeInterval second){
    return dispatch_time(DISPATCH_TIME_NOW, (int64_t)(second * NSEC_PER_SEC));
}

/**
 Returns a dispatch_wall_time delay from now.
 */
static inline dispatch_time_t dispatch_walltime_delay(NSTimeInterval second) {
    return dispatch_walltime(DISPATCH_TIME_NOW, (int64_t)(second * NSEC_PER_SEC));
}

/**
 Returns a dispatch_wall_time from NSDate.
 */
static inline dispatch_time_t dispatch_walltime_date(NSDate *date) {
    NSTimeInterval interval;
    double second, subsecond;
    struct timespec time;
    dispatch_time_t milestone;
    
    interval = [date timeIntervalSince1970];
    subsecond = modf(interval, &second);
    time.tv_sec = second;
    time.tv_nsec = subsecond * NSEC_PER_SEC;
    milestone = dispatch_walltime(&time, 0);
    return milestone;
}

/**
 Whether in main queue/thread.
 */
static inline bool dispatch_is_main_queue(){
    return pthread_main_np() != 0;
}
/**
 Submits a block for asynchronous execution on a main queue and returns immediately.
 */
static inline void dispatch_async_on_main_queue(void (^block)()){
    
    if (pthread_main_np()) {
        block();
    }else{
        dispatch_async(dispatch_get_main_queue(), block);
    }
    
}
/**
 Submits a block for execution on a main queue and waits until the block completes.
 */
static inline void dispatch_sync_on_main_queue(void (^block)()){
    
    if (pthread_main_np()) {
        block();
    }else{
        dispatch_sync(dispatch_get_main_queue(), block);
    }

}

/**
 *submits globe queue async
 */
static inline void dispatch_async_on_global_queue(void (^block)()){
    
    dispatch_async(dispatch_get_global_queue(0, 0), block);
    
}
/**
 *submits globe queue sync
 */
static inline void dispatch_sync_on_global_queue(void (^block)()){
    
    dispatch_sync(dispatch_get_global_queue(0, 0), block);
    
}

/**
 Initialize a pthread mutex.
 */
static inline void pthread_mutex_init_recursive(pthread_mutex_t *mutex, bool recursive) {
#define KCMUTEX_ASSERT_ON_ERROR(x_) do { \
__unused volatile int res = (x_); \
assert(res == 0); \
} while (0)
    assert(mutex != NULL);
    if (!recursive) {
        KCMUTEX_ASSERT_ON_ERROR(pthread_mutex_init(mutex, NULL));
    } else {
        pthread_mutexattr_t attr;
        KCMUTEX_ASSERT_ON_ERROR(pthread_mutexattr_init (&attr));
        KCMUTEX_ASSERT_ON_ERROR(pthread_mutexattr_settype (&attr, PTHREAD_MUTEX_RECURSIVE));
        KCMUTEX_ASSERT_ON_ERROR(pthread_mutex_init (mutex, &attr));
        KCMUTEX_ASSERT_ON_ERROR(pthread_mutexattr_destroy (&attr));
    }
#undef KCMUTEX_ASSERT_ON_ERROR
}


KC_EXTERN_C_END









#endif /* KCKitMacro_h */
