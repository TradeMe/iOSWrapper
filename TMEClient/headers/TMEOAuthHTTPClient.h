//
//  TMOAuthHTTPClient.h
//  TMAPIClient
//
//  Created by Simon Cook on 18/06/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

#import "AFHTTPClient.h"

#define TMEOAuthToken @"oauth_token"
#define TMEOAuthTokenSecret @"oauth_token_secret"

@class OAuthCredentials;

extern NSString * const TMEOAuthFailedWithTokenInvalidNotification;

/**
 This class exposes properties and methods to help with the process of signing your http requests with an OAuth signature.
 */
@interface TMEOAuthHTTPClient : AFHTTPClient

/**
 Gets and sets the OAuth credentials associated with the client.
 
 The credentials are the access token and secret returned Trade Me server.
 */
@property (strong, nonatomic) OAuthCredentials *oauthCredentials;

/**
 Gets and sets the consumer key used by the http client.
 
 For information on how to obtain a consumer key, see http://developer.trademe.co.nz/api-overview/registering-an-application/
 */
@property (strong, nonatomic) NSString *consumerKey;

/**
 Gets and sets the consumer secret used by the http client.
 
 For information on how to obtain a consumer key, see http://developer.trademe.co.nz/api-overview/registering-an-application/
 */
@property (strong, nonatomic) NSString *consumerSecret;

/**
 Gets and sets the last http operation that was executed by the client.
 */
@property (strong, nonatomic) AFHTTPRequestOperation *operationLastRequest;

/**
 Gets and sets the service name used by the client to cache credentials.
 */
@property (strong, nonatomic) NSString *serviceName;

/**
 Returns the authorization header given the path (e.g, /v1/Favourites/Sellers.json), the http method and the query string parameters.
 */
- (NSString *)getAuthorizationHeaderForPath:(NSString *)path
                                     method:(NSString *)method
                            queryParameters:(NSDictionary *)queryParameters;

/**
 Returns the authorization header given the path (e.g, /v1/Favourites/Sellers.json), the base url (e.g, http://api.trademe.co.nz), the http method and the query string parameters.
 */
- (NSString *)getAuthorizationHeaderForPath:(NSString *)path
                                    baseUrl:(NSURL *)baseUrl
                                     method:(NSString *)method
                            queryParameters:(NSDictionary *)queryParameters;

/**
 Returns the authorization header given the path (e.g, /v1/Favourites/Sellers.json), the base url (e.g, http://api.trademe.co.nz), the http method and the query string parameters
 and the user token and secret to use when generating the OAuth signature.
 */
- (NSString *)getAuthorizationHeaderForPath:(NSString *)path
                                    baseUrl:(NSURL *)baseUrl
                                     method:(NSString *)method
                            queryParameters:(NSDictionary *)queryParameters
                                  userToken:(NSString *)userToken
                                 userSecret:(NSString *)userSecret;

/**
 Caches the specified user token, secret and member id to the device.
 */
- (void)saveUserToken:(NSString *)userToken_ secret:(NSString *)userSecret_ memberId:(NSString *)memberId_;

/**
 Returns whether the client has enough information to allow it to successfully sign an http request
 */
- (BOOL)canSignRequest;

/**
 Returns the member id of the currently logged in user.
 */
- (NSNumber *)memberId;

@end

#pragma mark - OAuth
/**
 Class for storing the OAuth token and secret.
 */
@interface OAuthCredentials : NSObject

/**
 Gets and sets the user token.
 */
@property (nonatomic, strong) NSString *token;

/**
 Gets and sets the user secret.
 */
@property (nonatomic, strong) NSString *secret;

/**
 Create an instance of this class passing through the user token and secret.
 */
- (id)initWithToken:(NSString *)token_ secret:(NSString *)secret_;

@end
