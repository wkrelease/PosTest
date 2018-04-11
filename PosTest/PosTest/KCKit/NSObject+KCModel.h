//
//  NSObject+KCModel.h
//  KCKit
//
//  Created by king on 16/2/29.
//  Copyright © 2016年 KC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (KCModel)

+ (instancetype)modelWithJSON:(id)json;
+ (instancetype)modelWithDictionary:(NSDictionary *)dictionary;
- (BOOL)modelSetWithJSON:(id)json;
- (BOOL)modelSetWithDictionary:(NSDictionary *)dic;
- (id)modelToJSONObject;
- (NSData *)modelToJSONData;
- (NSString *)modelToJSONString;
- (id)modelCopy;
- (void)modelEncodeWithCoder:(NSCoder *)aCoder;
- (id)modelInitWithCoder:(NSCoder *)aDecoder;
- (NSUInteger)modelHash;
- (BOOL)modelIsEqual:(id)model;

@end


@interface NSArray (KCModel)

+ (NSArray *)modelArrayWithClass:(Class)cls json:(id)json;

@end


@interface NSDictionary (KCModel)

+ (NSDictionary *)modelDictionaryWithClass:(Class)cls json:(id)json;

@end


@protocol KCModel <NSObject>
@optional
+ (NSDictionary *)modelCustomPropertyMapper;
+ (NSDictionary *)modelContainerPropertyGenericClass;
+ (NSArray *)modelPropertyBlacklist;
+ (NSArray *)modelPropertyWhitelist;
- (BOOL)modelCustomTransformFromDictionary:(NSDictionary *)dic;
- (BOOL)modelCustomTransformToDictionary:(NSMutableDictionary *)dic;

@end



