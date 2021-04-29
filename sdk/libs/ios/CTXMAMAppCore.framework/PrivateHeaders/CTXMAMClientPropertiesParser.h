//
//  CTXMAMClientPropertiesParser.h
//  CTXMAMAppCore
//
//  Created by Daniel Romano on 4/2/19.
//  Copyright © 2019 Citrix Systems, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CTXMAMClientPropertiesParser : NSObject <NSXMLParserDelegate>

-(nullable NSDictionary *) clientPropertiesFromXMLData:(NSData *) xmlData;

@end

NS_ASSUME_NONNULL_END
