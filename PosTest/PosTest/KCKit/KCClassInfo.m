//
//  KCClassInfo.m
//  KCKit
//
//  Created by king on 16/2/29.
//  Copyright © 2016年 KC. All rights reserved.
//

#import "KCClassInfo.h"

#import <objc/runtime.h>

#import <libkern/OSAtomic.h>


KCEncodingType KCEncodingGetType(const char *typeEncoding) {
    char *type = (char *)typeEncoding;
    if (!type) return KCEncodingTypeUnknown;
    size_t len = strlen(type);
    if (len == 0) return KCEncodingTypeUnknown;
    
    KCEncodingType qualifier = 0;
    bool prefix = true;
    while (prefix) {
        switch (*type) {
            case 'r': {
                qualifier |= KCEncodingTypeQualifierConst;
                type++;
            } break;
            case 'n': {
                qualifier |= KCEncodingTypeQualifierIn;
                type++;
            } break;
            case 'N': {
                qualifier |= KCEncodingTypeQualifierInout;
                type++;
            } break;
            case 'o': {
                qualifier |= KCEncodingTypeQualifierOut;
                type++;
            } break;
            case 'O': {
                qualifier |= KCEncodingTypeQualifierBycopy;
                type++;
            } break;
            case 'R': {
                qualifier |= KCEncodingTypeQualifierByref;
                type++;
            } break;
            case 'V': {
                qualifier |= KCEncodingTypeQualifierOneway;
                type++;
            } break;
            default: { prefix = false; } break;
        }
    }
    
    len = strlen(type);
    if (len == 0) return KCEncodingTypeUnknown | qualifier;
    
    switch (*type) {
        case 'v': return KCEncodingTypeVoid | qualifier;
        case 'B': return KCEncodingTypeBool | qualifier;
        case 'c': return KCEncodingTypeInt8 | qualifier;
        case 'C': return KCEncodingTypeUInt8 | qualifier;
        case 's': return KCEncodingTypeInt16 | qualifier;
        case 'S': return KCEncodingTypeUInt16 | qualifier;
        case 'i': return KCEncodingTypeInt32 | qualifier;
        case 'I': return KCEncodingTypeUInt32 | qualifier;
        case 'l': return KCEncodingTypeInt32 | qualifier;
        case 'L': return KCEncodingTypeUInt32 | qualifier;
        case 'q': return KCEncodingTypeInt64 | qualifier;
        case 'Q': return KCEncodingTypeUInt64 | qualifier;
        case 'f': return KCEncodingTypeFloat | qualifier;
        case 'd': return KCEncodingTypeDouble | qualifier;
        case 'D': return KCEncodingTypeLongDouble | qualifier;
        case '#': return KCEncodingTypeClass | qualifier;
        case ':': return KCEncodingTypeSEL | qualifier;
        case '*': return KCEncodingTypeCString | qualifier;
        case '?': return KCEncodingTypePointer | qualifier;
        case '[': return KCEncodingTypeCArray | qualifier;
        case '(': return KCEncodingTypeUnion | qualifier;
        case '{': return KCEncodingTypeStruct | qualifier;
        case '@': {
            if (len == 2 && *(type + 1) == '?')
                return KCEncodingTypeBlock | qualifier;
            else
                return KCEncodingTypeObject | qualifier;
        } break;
        default: return KCEncodingTypeUnknown | qualifier;
    }
}

@implementation KCClassIvarInfo

- (instancetype)initWithIvar:(Ivar)ivar {
    if (!ivar) return nil;
    self = [super init];
    _ivar = ivar;
    const char *name = ivar_getName(ivar);
    if (name) {
        _name = [NSString stringWithUTF8String:name];
    }
    _offset = ivar_getOffset(ivar);
    const char *typeEncoding = ivar_getTypeEncoding(ivar);
    if (typeEncoding) {
        _typeEncoding = [NSString stringWithUTF8String:typeEncoding];
        _type = KCEncodingGetType(typeEncoding);
    }
    return self;
}

@end


@implementation KCClassMethodInfo

- (instancetype)initWithMethod:(Method)method {
    if (!method) return nil;
    self = [super init];
    _method = method;
    _sel = method_getName(method);
    _imp = method_getImplementation(method);
    const char *name = sel_getName(_sel);
    if (name) {
        _name = [NSString stringWithUTF8String:name];
    }
    const char *typeEncoding = method_getTypeEncoding(method);
    if (typeEncoding) {
        _typeEncoding = [NSString stringWithUTF8String:typeEncoding];
    }
    char *returnType = method_copyReturnType(method);
    if (returnType) {
        _returnTypeEncoding = [NSString stringWithUTF8String:returnType];
        free(returnType);
    }
    unsigned int argumentCount = method_getNumberOfArguments(method);
    if (argumentCount > 0) {
        NSMutableArray *argumentTypes = [NSMutableArray new];
        for (unsigned int i = 0; i < argumentCount; i++) {
            char *argumentType = method_copyArgumentType(method, i);
            if (argumentType) {
                NSString *type = [NSString stringWithUTF8String:argumentType];
                [argumentTypes addObject:type ? type : @""];
                free(argumentType);
            } else {
                [argumentTypes addObject:@""];
            }
        }
        _argumentTypeEncodings = argumentTypes;
    }
    return self;
}

@end



@implementation KCClassPropertyInfo

- (instancetype)initWithProperty:(objc_property_t)property {
    if (!property) return nil;
    self = [self init];
    _property = property;
    const char *name = property_getName(property);
    if (name) {
        _name = [NSString stringWithUTF8String:name];
    }
    
    KCEncodingType type = 0;
    unsigned int attrCount;
    objc_property_attribute_t *attrs = property_copyAttributeList(property, &attrCount);
    for (unsigned int i = 0; i < attrCount; i++) {
        switch (attrs[i].name[0]) {
            case 'T': { // Type encoding
                if (attrs[i].value) {
                    _typeEncoding = [NSString stringWithUTF8String:attrs[i].value];
                    type = KCEncodingGetType(attrs[i].value);
                    if (type & KCEncodingTypeObject) {
                        size_t len = strlen(attrs[i].value);
                        if (len > 3) {
                            char name[len - 2];
                            name[len - 3] = '\0';
                            memcpy(name, attrs[i].value + 2, len - 3);
                            _cls = objc_getClass(name);
                        }
                    }
                }
            } break;
            case 'V': { // Instance variable
                if (attrs[i].value) {
                    _ivarName = [NSString stringWithUTF8String:attrs[i].value];
                }
            } break;
            case 'R': {
                type |= KCEncodingTypePropertyReadonly;
            } break;
            case 'C': {
                type |= KCEncodingTypePropertyCopy;
            } break;
            case '&': {
                type |= KCEncodingTypePropertyRetain;
            } break;
            case 'N': {
                type |= KCEncodingTypePropertyNonatomic;
            } break;
            case 'D': {
                type |= KCEncodingTypePropertyDynamic;
            } break;
            case 'W': {
                type |= KCEncodingTypePropertyWeak;
            } break;
            case 'P': {
                type |= KCEncodingTypePropertyGarbage;
            } break;
            case 'G': {
                type |= KCEncodingTypePropertyCustomGetter;
                if (attrs[i].value) {
                    _getter = [NSString stringWithUTF8String:attrs[i].value];
                }
            } break;
            case 'S': {
                type |= KCEncodingTypePropertyCustomSetter;
                if (attrs[i].value) {
                    _setter = [NSString stringWithUTF8String:attrs[i].value];
                }
            } break;
            default:
                break;
        }
    }
    if (attrs) {
        free(attrs);
        attrs = NULL;
    }
    
    _type = type;
    if (_name.length) {
        if (!_getter) {
            _getter = _name;
        }
        if (!_setter) {
            _setter = [NSString stringWithFormat:@"set%@%@:", [_name substringToIndex:1].uppercaseString, [_name substringFromIndex:1]];
        }
    }
    return self;
}

@end


@implementation KCClassInfo{
    
    BOOL _needUpdate;

}

- (instancetype)initWithClass:(Class)cls{
    
    if (!cls) {
        return nil;
    }
    self = [super init];
    _cls = cls;
    _superCls = class_getSuperclass(cls);
    _isMeta = class_isMetaClass(cls);
    if (!_isMeta) {
        _metaCls = objc_getMetaClass(class_getName(cls));
    }
    _name = NSStringFromClass(cls);
    [self _update];
    _superClassInfo = [self.class classInfoWithClass:_superCls];
    return self;
}

- (instancetype)initWithClassName:(NSString *)className {
    Class cls = NSClassFromString(className);
    return [self initWithClass:cls];
}

- (void)_update {
    _ivarInfos = nil;
    _methodInfos = nil;
    _propertyInfos = nil;
    
    Class cls = self.cls;
    unsigned int methodCount = 0;
    Method *methods = class_copyMethodList(cls, &methodCount);
    if (methods) {
        NSMutableDictionary *methodInfos = [NSMutableDictionary new];
        _methodInfos = methodInfos;
        for (unsigned int i = 0; i < methodCount; i++) {
            KCClassMethodInfo *info = [[KCClassMethodInfo alloc] initWithMethod:methods[i]];
            if (info.name) methodInfos[info.name] = info;
        }
        free(methods);
    }
    unsigned int propertyCount = 0;
    objc_property_t *properties = class_copyPropertyList(cls, &propertyCount);
    if (properties) {
        NSMutableDictionary *propertyInfos = [NSMutableDictionary new];
        _propertyInfos = propertyInfos;
        for (unsigned int i = 0; i < propertyCount; i++) {
            KCClassPropertyInfo *info = [[KCClassPropertyInfo alloc] initWithProperty:properties[i]];
            if (info.name) propertyInfos[info.name] = info;
        }
        free(properties);
    }
    
    unsigned int ivarCount = 0;
    Ivar *ivars = class_copyIvarList(cls, &ivarCount);
    if (ivars) {
        NSMutableDictionary *ivarInfos = [NSMutableDictionary new];
        _ivarInfos = ivarInfos;
        for (unsigned int i = 0; i < ivarCount; i++) {
            KCClassIvarInfo *info = [[KCClassIvarInfo alloc] initWithIvar:ivars[i]];
            if (info.name) ivarInfos[info.name] = info;
        }
        free(ivars);
    }
    _needUpdate = NO;
}

- (void)setNeedUpdate {
    _needUpdate = YES;
}

+ (instancetype)classInfoWithClass:(Class)cls {
    if (!cls) return nil;
    static CFMutableDictionaryRef classCache;
    static CFMutableDictionaryRef metaCache;
    static dispatch_once_t onceToken;
    static OSSpinLock lock;
    dispatch_once(&onceToken, ^{
        classCache = CFDictionaryCreateMutable(CFAllocatorGetDefault(), 0, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
        metaCache = CFDictionaryCreateMutable(CFAllocatorGetDefault(), 0, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
        lock = OS_SPINLOCK_INIT;
    });
    OSSpinLockLock(&lock);
    KCClassInfo *info = CFDictionaryGetValue(class_isMetaClass(cls) ? metaCache : classCache, (__bridge const void *)(cls));
    if (info && info->_needUpdate) {
        [info _update];
    }
    OSSpinLockUnlock(&lock);
    if (!info) {
        info = [[KCClassInfo alloc] initWithClass:cls];
        if (info) {
            OSSpinLockLock(&lock);
            CFDictionarySetValue(info.isMeta ? metaCache : classCache, (__bridge const void *)(cls), (__bridge const void *)(info));
            OSSpinLockUnlock(&lock);
        }
    }
    return info;
}

+ (instancetype)classInfoWithClassName:(NSString *)className {
    Class cls = NSClassFromString(className);
    return [self classInfoWithClass:cls];
}


@end

































