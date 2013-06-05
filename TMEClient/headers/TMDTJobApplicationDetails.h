//
//  TMDTAgent.h
//  TMAPIClient
//
//  Created by Nick Parfene on 25/05/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

/**
 Indicates whether the job can be applied for online.
 */
typedef NS_ENUM(NSInteger, TMDTJobApplicationType) {
    TMDTJobApplicationTypeNone = 0,         //-- Applying online is not supported.
    TMDTJobApplicationTypeViaTradeMe = 1,   //-- Apply online via Trade Me.
    TMDTJobApplicationTypeWebsite = 2       //-- Apply online via a third-party website.
};


/**
 Class contains contact and 'apply online' application details.
 
 For more information, see; http://developer.trademe.co.nz/api-reference/search-methods/jobs-search/
 */
@interface TMDTJobApplicationDetails : NSObject

/**
 Indicates whether the job can be applied for online.
 */
@property (assign, nonatomic) TMDTJobApplicationType jobApplicationType;

/**
 The name of the person to contact.
 */
@property (strong, nonatomic) NSString *contactName;

/**
 A contact phone number.
 */
@property (strong, nonatomic) NSString *phoneNumber;

/**
 The URL of the job agency’s website.
 */
@property (strong, nonatomic) NSString *website;

/**
 The URL to the Trade Me Apply Online page (if any).
 */
@property (strong, nonatomic) NSString *applyViaTradeMe;

/**
 Create an instance of this class passing through data from a dictionary
 */
- (id)initWithDictionary:(NSDictionary *)dictionaryJobApplicationDetails;

@end
