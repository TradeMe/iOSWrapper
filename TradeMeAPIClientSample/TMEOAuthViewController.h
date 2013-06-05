//
//  TMEOAuthViewController.h
//  TradeMeAPIClientSample
//
//  This view controller is responsible for logging a user into the Trade Me system using oauth.
//  For an overview of the oauth process used by Trade Me go to;
//  http://developer.trademe.co.nz/api-overview/authentication-authorisation/oauth/example-oauth-flow/
//
//  For an overview of oauth in general, go to;
//  http://en.wikipedia.org/wiki/OAuth
//
//  Created by Nick Parfene on 17/05/13.
//  Copyright (c) 2013 Trade Me. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol TMEOAuthViewControllerDelegate;

@interface TMEOAuthViewController : UIViewController <UIWebViewDelegate>

@property (weak, nonatomic) id<TMEOAuthViewControllerDelegate> delegate;

@end

/**
    The delegate of a TMEOAuthViewController object implements this protocol to perform specialized actions when the user has successfully logged into Trade Me using oauth.
 */
@protocol TMEOAuthViewControllerDelegate <NSObject>

/**
 Called when the user has successfully logged into Trade Me using oauth.
 */
- (void)oAuthViewControllerDidLogin;

@optional
/**
 Called when there was an error logging into Trade Me using oauth.
 */
- (void)oAuthViewController:(TMEOAuthViewController *)tmeAuthViewController didFailToLoginWithError:(NSError *)error;

@end