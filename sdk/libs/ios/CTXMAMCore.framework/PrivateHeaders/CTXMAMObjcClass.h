//
//  CTXMAMObjcClass.h
//  CitrixLoader
//
//  Created on 1/12/17.
//  Copyright © 2017 - 2019 Citrix Systems, Inc. All rights reserved.
//

#ifndef CTXMAMObjcClass_h
#define CTXMAMObjcClass_h

#import <Foundation/Foundation.h>
#import <objc/runtime.h>


NS_ASSUME_NONNULL_BEGIN
//CTXMAMClass_getInstanceSelectorImplementation
//Return back the current Instance Selector Implementation
//Cls:The class to hook
//Selector: The selector to hook
IMP _Nullable CTXMAMClass_getInstanceSelectorImplementation(Class cls, SEL name);

Method CTXMAMClass_getClassImplementedMethod(Class cls, SEL name);
Method CTXMAMClass_getInstanceImplementedMethod(Class cls, SEL name);

//CTXMAMClass_setInstanceSelectorImplementation
//Set the current Instance Selector Implementation and returns back the current Instance Selector Implementation
//If the Class implements the selector then the callOriginal will be used to hook
//If the Class does not implement it but one of its super classes does then the callSuper hook will be used.  It must call super
//Cls:The class to hook
//Selector: The selector to hook
//hookImplementation: The implementation to call when the selector is called
//originalImplementationBlock: Block that will return an ObjC function pointer we use a block so that we can call Super if there was never an implementation at that level
void CTXMAMClass_setInstanceSelectorImplementation(Class cls, SEL selector, IMP hookImplementation, void *_Nullable *_Nullable originalImplementation);

//CTXMAMClass_setClassSelectorImplementation
//Set the current Class Selector Implementation and returns back the current Class Selector Implementation
//If the Class implements the selector then the callOriginal will be used to hook
//If the Class does not implement it but one of its super classes does then the callSuper hook will be used.  It must call super
//Cls:The class to hook
//Selector: The selector to hook
//hookImplementation: The implementation to call when the selector is called
//originalImplementationBlock: Block that will return an ObjC function pointer we use a block so that we can call Super if there was never an implementation at that level
void CTXMAMClass_setClassSelectorImplementation(Class cls, SEL selector, IMP hookImplementation, void *_Nullable *_Nullable originalImplementation);


//CTXMAMClass_setInstanceSelectorBlockImplementation
//This installs a top Level hook for a class
//This out parameter originalImplementationBlock will return a block that will return back a ObjC function pointer (This block allow for late binding between the original implementation or a super call)
//cls: The class to hook
//selector:  The Selector to hook
//hookBlock: The block to call when the selector is called
//originalImplementation: ObjectC function pointer pointer that will return an ObjC function pointer
void CTXMAMClass_setInstanceSelectorBlockImplementation(Class cls, SEL selector, id hookBlock, void *_Nullable *_Nullable originalImplementation);

//CTXMAMClass_setClassSelectorBlockImplementation
//This installs a top Level hook for a class
//This out parameter originalImplementationBlock will return a block that will return back a ObjC function pointer (This block allow for late binding between the original implementation or a super call)
//cls: The class to hook
//selector:  The Selector to hook
//hookBlock: The block to call when the selector is called
//originalImplementation: ObjectC function pointer pointer that will return an ObjC function pointer
void CTXMAMClass_setClassSelectorBlockImplementation(Class cls, SEL selector, id hookBlock, void *_Nullable *_Nullable originalImplementation);


//CTXMAMClass_hookDelegateMethod
//This installs Delegate Hook if the class implements the delegate call
//cls: The class to hook
//selector:  The Selector to hook
//newSelectorName: The new selector to make the original implementation
//newImplementation: The implementation to assign to the original selector
//requiredHook: This allow the delegate to always hook independent of the Class being implemented the selector or not
BOOL CTXMAMClass_hookDelegateMethod(Class class, SEL selector, const char *newSelectorName, IMP newImplementation, BOOL requiredHook);
NS_ASSUME_NONNULL_END

#endif /* CTXMAMObjcClass_h */
