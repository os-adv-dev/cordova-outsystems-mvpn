#import "AppDelegate+mvpn.h"

implementation AppDelegate (AppDelegateMVPN)

- (BOOL)application:(UIApplication*)application didFinishLaunchingWithOptions:(NSDictionary*)launchOptions
{
    self.viewController = [[MainViewController alloc] init];
    [super application:application didFinishLaunchingWithOptions:launchOptions];
    
    //[CTXMAMLocalAuth setDelegate:self];
    [CTXMAMCore initializeSDKs];
    [CTXMAMCore setDelegate:self];
    [CTXMAMContainment setDelegate:self];
    [CTXMAMCompliance sharedInstance].delegate = self;
    
    CTXMAMConfigManager *ctxConfigManager = [CTXMAMConfigManager sharedConfigManager];
    [CTXMAMLogger CTXMAMLog_Initialize];
    
    return YES;
}

#pragma mark - Containment SDK

- (void) appIsOutsideGeofencingBoundary
{
   NSString *alertMsg = @"You have left the area that your organization designates for this app. Please return to the designated area and relaunch the app.";
   [self enforceAppUsageRestrictions:alertMsg];
}

- (void) appNeedsLocationServicesEnabled
{
   NSString *alertMsg = @"Your organization requires you to enable Location Services to run this app.";
   [self enforceAppUsageRestrictions:alertMsg];
}

-(void)showAlertMsg:(NSString *)alertMsg
{
   UIAlertView *toast = [[UIAlertView alloc] initWithTitle:nil
                                                   message:alertMsg
                                                  delegate:nil
                                         cancelButtonTitle:nil
                                         otherButtonTitles:nil, nil];
   [toast show];

   int duration = 3; // duration in seconds
   if ([alertMsg length] > 40)
       duration = 5; // allow more time to read longer messages
   dispatch_after(dispatch_time(DISPATCH_TIME_NOW, duration * NSEC_PER_SEC), dispatch_get_main_queue(), ^{
       [toast dismissWithClickedButtonIndex:0 animated:YES];
   });
}

-(void)enforceAppUsageRestrictions:(NSString *)alertMsg
{
   UIAlertController * alert = [UIAlertController
                                alertControllerWithTitle:@""
                                message:alertMsg
                                preferredStyle:UIAlertControllerStyleAlert];
   UIAlertAction * quitButton = [UIAlertAction actionWithTitle:@"Quit"
                                                         style:UIAlertActionStyleDestructive
                                                       handler:^(UIAlertAction * action) {
       id appdelegate =   [[UIApplication sharedApplication] delegate];
       [appdelegate applicationWillTerminate:[UIApplication sharedApplication]];
       exit(0); // terminate the app
   }];
   [alert addAction:quitButton];
   dispatch_async(dispatch_get_main_queue(), ^{
       UIViewController *topController = [UIApplication sharedApplication].keyWindow.rootViewController;
       [topController presentViewController:alert animated:YES completion:nil];
   });
}

#pragma mark - Local Auth SDK
- (void) maxOfflinePeriodWillExceedWarning:(NSTimeInterval) secondsToExpire
{
    NSLog(@"Received maxOfflinePeriodWillExceedWarning");
    NSString * alertTitle = @"Warning message from App:";
    NSString * alertMsg = [NSString stringWithFormat:@"Offline lease will expire in %f seconds. Please go online and login.", secondsToExpire];
    UIAlertController * alert = [UIAlertController
        alertControllerWithTitle:alertTitle
                         message:alertMsg
                  preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *actionOk = [UIAlertAction actionWithTitle:@"Ok"
                                                       style:UIAlertActionStyleDefault
                                                     handler:nil];
    [alert addAction:actionOk];
    dispatch_async(dispatch_get_main_queue(), ^{
        UIViewController *topController = [UIApplication sharedApplication].keyWindow.rootViewController;
        [topController presentViewController:alert animated:YES completion:nil];
    });
}

- (void) maxOfflinePeriodExceeded
{
    NSLog(@"Received maxOfflinePeriodExceeded");
    NSString * alertTitle = @"Error message from App:";
    NSString * alertMsg = @"Offline lease has expired. Please login again.";
    UIAlertController * alert = [UIAlertController
        alertControllerWithTitle:alertTitle
                         message:alertMsg
                  preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction * quitButton = [UIAlertAction actionWithTitle:@"Quit"
                                                       style:UIAlertActionStyleDestructive
                                                     handler:^(UIAlertAction * action) {
                                        NSLog(@"Application will terminate");
                                        id appdelegate =   [[UIApplication sharedApplication] delegate];
                                        [appdelegate applicationWillTerminate:[UIApplication sharedApplication]];
                                        exit(0); // terminate the app
                                    }];
    [alert addAction:quitButton];
    dispatch_async(dispatch_get_main_queue(), ^{
        UIViewController *topController = [UIApplication sharedApplication].keyWindow.rootViewController;
        [topController presentViewController:alert animated:YES completion:nil];
    });
}

- (void) devicePasscodeRequired
{
    NSLog(@"Received devicePasscodeRequired");
    NSString * alertTitle = @"Error message from App:";
    NSString * alertMsg = @"Please set the device passcode and Touch ID/FaceID since it is required when Inactivity Timer expires.";
    UIAlertController * alert = [UIAlertController
        alertControllerWithTitle:alertTitle
                         message:alertMsg
                  preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction * quitButton = [UIAlertAction actionWithTitle:@"Quit"
                                                       style:UIAlertActionStyleDestructive
                                                     handler:^(UIAlertAction * action) {
                                        NSLog(@"Application will terminate");
                                        id appdelegate =   [[UIApplication sharedApplication] delegate];
                                        [appdelegate applicationWillTerminate:[UIApplication sharedApplication]];
                                        exit(0); // terminate the app
                                    }];
    [alert addAction:quitButton];
    dispatch_async(dispatch_get_main_queue(), ^{
        UIViewController *topController = [UIApplication sharedApplication].keyWindow.rootViewController;
        [topController presentViewController:alert animated:YES completion:nil];
    });
}



#pragma mark - Core SDK
- (void) proxyServerSettingDetected
{
    NSLog(@"Received proxyServerSettingDetected");
    NSString * alertTitle = @"Error message from App:";
    NSString * alertMsg = @"Proxy server setting is detected. The network request is stopped, since configuring a proxy server is not allowed.";
    UIAlertController * alert = [UIAlertController
        alertControllerWithTitle:alertTitle
                         message:alertMsg
                  preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction * quitButton = [UIAlertAction actionWithTitle:@"Quit"
                                                       style:UIAlertActionStyleDestructive
                                                     handler:^(UIAlertAction * action) {
                                        NSLog(@"Application will terminate");
                                        id appdelegate =   [[UIApplication sharedApplication] delegate];
                                        [appdelegate applicationWillTerminate:[UIApplication sharedApplication]];
                                        exit(0); // terminate the app
                                    }];
    [alert addAction:quitButton];
    dispatch_async(dispatch_get_main_queue(), ^{
        UIViewController *topController = [UIApplication sharedApplication].keyWindow.rootViewController;
        [topController presentViewController:alert animated:YES completion:nil];
    });
}

@end