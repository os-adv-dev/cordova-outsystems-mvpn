//
//  GDataXMLHelper.h
//  ReceiverForiOS
//
//  Created on 2/9/12.
//  Copyright © 2012 - 2019 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CtxGDataXMLNode.h"

@interface CtxGDataXMLHelper : NSObject
+(NSString*)getStringValue:(GDataXMLElement_W*)rootElement forPath:(NSString*)path namespaces:(NSDictionary*) ns;
+(NSArray*)getStringValueArray:(GDataXMLElement_W*)rootElement forPath:(NSString*)path namespaces:(NSDictionary*) ns;
+(NSString*)getPropertyValue:(GDataXMLElement_W*)resourceElement namespaces:(NSDictionary*)ns forId:(NSString*)propertyId;
@end
