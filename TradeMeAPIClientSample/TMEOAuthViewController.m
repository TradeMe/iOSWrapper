//
//  TMEOAuthViewController.m
//  TradeMeAPIClientSample
//
//  Created by Nick Parfene on 17/05/13.
//  Copyright (c) 2013 Trade Me. All rights reserved.
//

#import "TMEOAuthViewController.h"

#warning Callback URL must be set before using the app
/**
 The callback URL is used by the App to determine when the OAuth webview returns.
 For more information, see: http://www.tmsandbox.co.nz/MyTradeMe/Api/RegisterNewApplication.aspx?
 */
#define TMECallbackURL              @"CALLBACK URL"

#define TMEURLBaseURL               @"https://secure.trademe.co.nz"
#define TMEURLRequestToken          @"/Oauth/RequestToken"
#define TMEURLAccessToken           @"/Oauth/AccessToken"
#define TMEURLRequestAuthorisation  @"https://secure.trademe.co.nz/Oauth/Authorize?oauth_token="

@interface TMEOAuthViewController ()

/**
 Webview to display the Trade Me login screen using oauth.
 */
@property (weak, nonatomic) IBOutlet UIWebView *webView;

/**
 Temporary url request object used to cache requests across asynchronous invocations to the web view.
 */
@property (strong, nonatomic) NSMutableURLRequest *request;

/**
 The temporary user token used only during the login process
 */
@property (strong, nonatomic) NSString *requestToken;

/**
 The temporary user secret used only during the login process
 */
@property (strong, nonatomic) NSString *requestSecret;

@property (weak, nonatomic) IBOutlet UIView *viewOverlayTop;
@property (weak, nonatomic) IBOutlet UIView *viewOverlayBottom;

@end

@implementation TMEOAuthViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    //-- we need to retrieve a temporary user token and secret (AKA the request token) from the server that will only be used during the login process    
    [self downloadRequestTokenAndSecretFromServer];
}

- (void)toggleOverlayVisible:(BOOL)visible
{
    [UIView animateWithDuration:0.3 animations:^{
        if (visible) {
            if (self.viewOverlayTop.center.y < 0) {                
                self.viewOverlayTop.center = CGPointMake(self.viewOverlayTop.center.x, self.viewOverlayTop.frame.size.height / 2);
                self.viewOverlayBottom.center = CGPointMake(self.viewOverlayBottom.center.x, self.view.frame.size.height - self.viewOverlayBottom.frame.size.height / 2);
            }
        }
        else {
            if (self.viewOverlayTop.center.y > 0) {
                self.viewOverlayTop.center = CGPointMake(self.viewOverlayTop.center.x, -self.viewOverlayTop.frame.size.height / 2);
                self.viewOverlayBottom.center = CGPointMake(self.viewOverlayBottom.center.x, self.view.frame.size.height + self.viewOverlayBottom.frame.size.height / 2);
            }
        }
    }];
}

- (void)downloadRequestTokenAndSecretFromServer
{
    TMEOAuthHTTPClient *oauthHttpClient = [TMEClient sharedInstance].client;
    
    //-- create the oauth authorisation header
    NSString *authorisationHeader = [oauthHttpClient getAuthorizationHeaderForPath:TMEURLRequestToken
                                                                           baseUrl:[NSURL URLWithString:TMEURLBaseURL]
                                                                            method:@"POST"
                                                                   queryParameters:@{ @"scope" : @"MyTradeMeRead,MyTradeMeWrite,BiddingAndBuying" }];
    
    //-- generate the url with the appropriate permissions required for your app
    NSURL *url = [NSURL URLWithString:[NSString stringWithFormat:@"%@%@?scope=MyTradeMeRead,MyTradeMeWrite,BiddingAndBuying", TMEURLBaseURL, TMEURLRequestToken]];
    self.request = [NSMutableURLRequest requestWithURL:url];
    [self.request setHTTPMethod:@"POST"];
    [self.request setValue:authorisationHeader forHTTPHeaderField:@"Authorization"];
    
    [NSURLConnection sendAsynchronousRequest:self.request queue:[NSOperationQueue mainQueue] completionHandler:^(NSURLResponse *response, NSData *data, NSError *error) {
        if (error) {
            if ([self.delegate respondsToSelector:@selector(oAuthViewController:didFailToLoginWithError:)]) {
                [self.delegate oAuthViewController:self didFailToLoginWithError:error];
            }
        }
        else {
            //-- success!  now we extract and cache the temporary user token and secret from the response
            //-- data, and create the oauth url that the webview will be redirected to in order to log in
            
            NSString *responseString = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
            NSDictionary *dictionaryOfAuthComponents = [responseString dictionaryFromSearchQueryString];
            
            self.requestToken = dictionaryOfAuthComponents[@"oauth_token"];
            self.requestSecret = dictionaryOfAuthComponents[@"oauth_token_secret"];
            
            NSString *requestStringAuth = [TMEURLRequestAuthorisation stringByAppendingString:dictionaryOfAuthComponents[@"oauth_token"]];
            NSURL *urlAuth = [NSURL URLWithString:requestStringAuth];
            NSURLRequest *requestToAuthenticateUser = [NSURLRequest requestWithURL:urlAuth];
            
            //-- load the oauth url into the web view
            [self.webView loadRequest:requestToAuthenticateUser];
        }
    }];
}

#pragma mark - Web View Delegate

- (void)webViewDidStartLoad:(UIWebView *)webView
{
    [self toggleOverlayVisible:YES];
}

- (void)webViewDidFinishLoad:(UIWebView *)webView
{
    [self toggleOverlayVisible:NO];
}

- (BOOL)webView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType
{
    NSLog(@"Received request: %@", request);
    
    if ([[request.URL description] containsString:TMECallbackURL]) {
        //-- the server has redirected the client to our callback, so now we need to extract the oauth verifier token and use it as
        //-- well as the temporary user token and secret to generate the final call to return the actual session token and secret.
        
        //-- extract the oauth_verifier
        NSDictionary *dictionaryOfAuthComponents = [[request.URL description] dictionaryFromSearchQueryString];
        NSString *oAuthVerifier = dictionaryOfAuthComponents[@"oauth_verifier"];
        NSLog(@"oauth_verifier = %@ ", oAuthVerifier);
                
        //-- download the final token and secret using the oauth verifier
        [self downloadAccessTokenAndSecretFromServerWithOAuthVerifier:oAuthVerifier];
        
        return NO;
    }

    return YES;
}

- (void)downloadAccessTokenAndSecretFromServerWithOAuthVerifier:(NSString *)oAuthVerifier
{
    TMEOAuthHTTPClient *oauthHttpClient = [TMEClient sharedInstance].client;
    
    //-- create the oauth authorisation header using the oauth verifier, the temporary user token and secret
    NSString *authorisationHeader = [oauthHttpClient getAuthorizationHeaderForPath:TMEURLAccessToken
                                                                           baseUrl:[NSURL URLWithString:TMEURLBaseURL]
                                                                            method:@"POST"
                                                                   queryParameters:@{ @"oauth_verifier" : oAuthVerifier }
                                                                         userToken:self.requestToken
                                                                        userSecret:self.requestSecret];
    
    NSURL *url = [NSURL URLWithString:[NSString stringWithFormat:@"%@%@", TMEURLBaseURL, TMEURLAccessToken]];
    self.request = [NSMutableURLRequest requestWithURL:url];
    [self.request setHTTPMethod:@"POST"];
    [self.request setValue:authorisationHeader forHTTPHeaderField:@"Authorization"];
    
    [NSURLConnection sendAsynchronousRequest:self.request queue:[NSOperationQueue mainQueue] completionHandler:^(NSURLResponse *response, NSData *data, NSError *error) {
        if (error) {
            NSLog(@"Error %@", error);
            if ([self.delegate respondsToSelector:@selector(oAuthViewController:didFailToLoginWithError:)]) {
                [self.delegate oAuthViewController:self didFailToLoginWithError:error];
            }
        }
        else {
            NSString *responseString = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
            
            //-- launch the webview with the oath_toke and oauth_token_secret
            NSDictionary *dictionaryOfAuthComponents = [responseString dictionaryFromSearchQueryString];
            
            
            //-- IMPORTANT!  EXTRACT THE FINAL USER TOKEN AND SECRET AND SAVE THESE IN API CLIENT
            //-- these final tokens are used to sign every api request that the user makes.
            NSString *userToken = dictionaryOfAuthComponents[@"oauth_token"];
            NSString *userSecret = dictionaryOfAuthComponents[@"oauth_token_secret"];
            [[TMEClient sharedInstance].client saveUserToken:userToken secret:userSecret memberId:nil];
                        
            //-- call the delegate that the user has successfully logged in.
            [self.delegate oAuthViewControllerDidLogin];
        }
    }];
}

@end
