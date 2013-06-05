//
//  TMDTAgency.h
//  TMAPIClient
//
//  Created by Nick Parfene on 25/05/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, TMDTAgencySubtype) {
    TMDTAgencySubypeNone = 0,
    TMDTAgencySubypePropertyIndependent = 1,
    TMDTAgencySubypePropertyAggregator = 2,
    TMDTAgencySubypePropertyRealEstateAgency = 3,
    TMDTAgencySubypePropertyRvaSubscription = 4,
    TMDTAgencySubypePropertyRvaDirect = 5,
    TMDTAgencySubypePropertyBusinessAggregator = 6,
    TMDTAgencySubypePropertyIndependantWithRentals = 17,
    TMDTAgencySubypePropertyAggregatorWithRentals = 18,
    TMDTAgencySubypePropertyRealEstateAgencyWithRentals = 19,
    TMDTAgencySubypePropertyRvaSubscriptionWithRentals = 20,
    TMDTAgencySubypePropertyRvaDirectWithRentals = 21,
    TMDTAgencySubypePropertyBusinessAggregatorWithRentals = 22,
    TMDTAgencySubypeJobAgentEmployer = 256,
    TMDTAgencySubypeJobAgentAggregator = 512,
    TMDTAgencySubypeJobsAgentRecruitmentAgency = 768,
    TMDTAgencySubypeJobsAgentPrepaid = 1024
};

typedef NS_ENUM(NSInteger, TMDTAgencyType) {
    TMDTAgencyTypeNone,
    TMDTAgencyTypeJob,
    TMDTAgencyTypeProperty,
    TMDTAgencyTypeMotor
};

/**
 Contains information about an agency that has listings in Trade Me.
 
 For more information see; http://developer.trademe.co.nz/api-reference/listing-methods/retrieve-the-details-of-a-single-listing/
 */
@interface TMDTAgency : NSObject

/**
 The ID of the company.
 */
@property (strong, nonatomic) NSNumber *agencyId;

/**
 The name of the company.
 */
@property (strong, nonatomic) NSString *name;

/**
 The address of the company.
 */
@property (strong, nonatomic) NSString *address;

/**
 The city of the company.
 */
@property (strong, nonatomic) NSString *city;

/**
 The suburb of the company.
 */
@property (strong, nonatomic) NSString *suburb;

/**
 The email address of the company.
 */
@property (strong, nonatomic) NSString *email;

/**
 A fax number for the company.
 */
@property (strong, nonatomic) NSString *faxNumber;

/**
 A contact phone number for the company.
 */
@property (strong, nonatomic) NSString *phoneNumber;

/**
 The URL of the company website.
 */
@property (strong, nonatomic) NSString *website;

/**
 A URL for the company logo.
 */
@property (strong, nonatomic) NSString *logoUrl;

/**
 The sub type of agent.
 */
@property (nonatomic) TMDTAgencySubtype agencySubtype;

/**
 Indicates whether the agency is an REAA licensed property agency
 */
@property (nonatomic) BOOL isLicensedPropertyAgency;

/**
 The type of company.
 */
@property (nonatomic) TMDTAgencyType agencyType;

/**
 The contact details of contacts within the agency.
 */
@property (strong, nonatomic) NSArray *arrayOfAgents;

/**
 Create an instance of this class passing through data from a dictionary
 */
- (id)initWithDictionary:(NSDictionary *)dictionaryAgency;

@end
