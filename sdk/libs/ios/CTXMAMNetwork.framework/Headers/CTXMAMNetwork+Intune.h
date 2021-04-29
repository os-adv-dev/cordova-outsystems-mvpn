//
//  CTXMAMNetwork+Intune.h
//  CTXMAMNetwork
//
//  Created by Shikha Shah on 7/10/19.
//  Copyright © 2019 Citrix Systems Inc. All rights reserved.
//

#import <CTXMAMNetwork/CTXMAMNetwork.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^CTXMAMNetworkEventBlock)(NSError * error);

typedef enum gatewaySessionErrorReturnType {
    
    GatewaySessionNoError = 0,
    GatewaySessionWrongCredentials,
    GatewaySessionGatewayUnreachable,
    GatewaySessionADALAuthPromptRequired,
    GatewaySessionLoginFailed,
    GatewaySessionInvalidInput,
    GatewaySessionDefaultError
    
}gatewaySessionErrorReturnType;

@interface CTXMAMNetwork (Intune)

/*!
 @brief Sets the Intune policy configuration dictionary
 @param policyDictionary A NSDictionary object containing a list of policy keys and values to be used for creating the Gateway session.
 */
+(void) setAppConfigPolicy: (NSDictionary *) policyDictionary;


/*!
 @brief Stops a gateway session with the NetScaler server
 @returns A NSError object which will contain the error code in case of an error during the session shutdown or error code 0 in case of success.
 */
+(NSError *) stopGatewaySession;

/*!
 @brief Checks to see if there is a NetScaler gateway session established.
 @returns YES if a session already exists, otherwise NO.
 */
+(BOOL) isGatewaySessionRunning;

/*!
 @brief Starts a gateway session with the NetScaler server
 @param token The ADAL token to be used for authentication with the NetScaler
 @param completionHandler A pointer to a block or function that will be responsible for handing any actions required once the session is establish or any errors which might occur during session creation.
 */
+(void)startGatewaySessionWithToken:(NSString *)token completionHandler:(CTXMAMNetworkEventBlock)completionHandler;


@end

NS_ASSUME_NONNULL_END
