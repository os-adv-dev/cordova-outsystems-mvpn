//
//  CtxDataXML.h
//  CtxDataXML
//
//  Created by davidli on 7/24/16.
//  Copyright © 2016 - 2019 Citrix Systems, Inc. All rights reserved.
//




@interface CtxDataXML : NSObject


// Class initializers
- init;

// Singleton factory method
+ (CtxDataXML *)sharedCtxDataXML;


+ (NSDictionary *)policiesFromBase64String:(NSString *)base64Xml;
+ (NSDictionary *)policiesFromXMLString:(NSString *)policyXml;
+ (NSString*)addPolicyNodeString:(NSString*)newPolicyNode
			toBase64PolicyString:(NSString*)base64Xml
			removeDuplicateNodes:(BOOL)dRemoveDuplicateNodes
						   error:(NSError**)error;
+ (NSString*)addPolicyNodes:(id)newPolicyNodes
	   toBase64PolicyString:(NSString*)base64Xml
	   removeDuplicateNodes:(BOOL)bRemoveDuplicateNodes
					  error:(NSError**)error;
+ (NSString*)updatePolicies:(NSDictionary*)newPolicies
       toBase64PolicyString:(NSString*)base64Xml
                      error:(NSError**)error;



@end


