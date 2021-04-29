//
//  Swizzling.h
//  WrapLibConsumer
//
//  Created by Jaspreet Singh on 10/22/12.
//  Copyright © 2012 - 2019 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum _SwizzlingResult
{
    SwizzlingMethodUnchanged = 0,
    SwizzlingMethodExchanged,
    SwizzlingMethodCreated
} SwizzlingResult, * PSwizzlingResult;

// Block that captures the provided orig pointer and returns a block for swizzling it
typedef id (^SwizzleBlockFactory)(IMP, SEL);

@interface Swizzling : NSObject

+ (void) swizzleMethod:(SEL) origSel fromClass:(Class) origClass withMethod:(SEL)newSel inClass:(Class) swizzleClass;
+ (void) swizzleClassMethod:(SEL) origSel withClass:(Class) origClass withMethod:(SEL)newSel newClass:(Class) newClass;
+ (SwizzlingResult) swizzleInstanceMethod:(SEL) origSel fromClass:(Class) origClass withMethod:(SEL) newSel inClass:(Class) swizzleClass createIfDoesNotExists:(BOOL) bCreate;
+ (BOOL) addMethod:(SEL) origSelector fromClass:(Class) origClass toClass:(Class) newClass;
+ (BOOL) addMethod:(SEL) newSel fromClass:(Class) newClass thenSwizzleMethod:(SEL) origSel inClass:(Class) origClass;
+ (BOOL) addAppCall:(SEL) appCall inClass:(Class) appClass ctxCall:(SEL) ctxAppCall origCall:(SEL) origAppCall inClass:(Class) ctxClass createIfNotImplemented:(BOOL) createIfNotImplemented;

+(BOOL) swizzleSEL:(SEL)    actualCall
           ofClass:(Class)  targetClass
           withSEL:(SEL)    ctxReplacementCall
           ofClass:(Class)  sourceClass
       originalSEL:(SEL)    originalActualCall
            create:(BOOL)   createIfNotImplemented;

+(void) swizzleInstanceMethod:(SEL) origSel inClass:(Class) swizzleClass withBlockFactory:(SwizzleBlockFactory) swizzleBlockFactory;
+(void) swizzleClassMethod:(SEL) origSel inClass:(Class) swizzleClass withBlockFactory:(SwizzleBlockFactory) swizzleBlockFactory;

+(void) swizzleAllInstancesOfInstanceMethod:(SEL) selector withBlockFactory:(SwizzleBlockFactory) swizzleBlockFactory;
+(void) swizzleAllInstancesOfClassMethod:(SEL) selector withBlockFactory:(SwizzleBlockFactory) swizzleBlockFactory;



@end
