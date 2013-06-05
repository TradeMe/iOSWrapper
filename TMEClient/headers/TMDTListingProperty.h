//
//  TMDTListingProperty.h
//  TMAPIClient
//
//  Created by Nick Parfene on 25/05/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

#import "TMDTListing.h"

@class TMDTAgent;
@class TMDTAgency;

/**
 Represents a listing that contains property-specific information.
 */
@interface TMDTListingProperty : TMDTListing

/**
 The address to display.
 */
@property (strong, nonatomic) NSString *address;

/**
 The district the property is located in.
 */
@property (strong, nonatomic) NSString *district;

/**
 The reference to the agency.
 */
@property (strong, nonatomic) NSString *agencyReference;

/**
 A list of the amenities in the area.
 */
@property (strong, nonatomic) NSString *amenities;

/**
 The area of the house, in square metres.
 */
@property (nonatomic) NSInteger area;

/**
 The area of the land, in square metres.
 */
@property (nonatomic) NSInteger landArea;

/**
 The date the property is available from.
 */
@property (strong, nonatomic) NSString *availableFrom;

/**
 The number of bedrooms in the property.
 */
@property (nonatomic) NSInteger bathrooms;

/**
 The number of bathrooms in the property.
 */
@property (nonatomic) NSInteger bedrooms;

/**
 A description of the ideal tenant (are they tidy, a professional couple, etc).
 */
@property (strong, nonatomic) NSString *idealTenant;

/**
 One or more keywords to use in a search query.
 */
@property (strong, nonatomic) NSString *keywords;

/**
 The listing group.
 */
@property (strong, nonatomic) NSString *listingGroup;

/**
 The maximum number of tenents.
 */
@property (nonatomic) NSInteger maxTenants;

/**
 Information on the availability of parking.
 */
@property (strong, nonatomic) NSString *parkingOrGaraging;

/**
 The property type.
 */
@property (strong, nonatomic) NSString *propertyType;

/**
 The rateable value of the property.
 */
@property (nonatomic) NSInteger rateableValue;

/**
 The rent payable per week, in NZD.
 */
@property (strong, nonatomic) NSNumber *rentPerWeek;

/**
 Instructions on how to view the property.
 */
@property (strong, nonatomic) NSString *viewingInstructions;

/**
 A description of what is included in the rent (if furnished).
 */
@property (strong, nonatomic) NSString *whiteware;

/**
 The property ID. This is different from the listing ID.
 */
@property (strong, nonatomic) NSString *propertyId;

/**
 The names of any adjacent suburbs.
 */
@property (strong, nonatomic) NSString *adjacentSuburbNames;

/**
 The IDs of any adjacent suburbs.
 */
@property (strong, nonatomic) NSString *adjacentSuburbIds;

/**
 The ID of the district the property is in.
 */
@property (strong, nonatomic) NSNumber *districtId;

/**
 Details of the agency this property was listed by.
 */
@property (strong, nonatomic) TMDTAgency *agency;

/**
 Indicates whether the village has care services (used in the retirement village api).
 */
@property (assign, nonatomic) BOOL hasCareServices;

/**
 Indicates whether the village is a member of Retirement Villages Association of New Zealand (used in the retirement village api).
*/
@property (assign, nonatomic) BOOL isRVAMember;

/**
 The registration number of the retirement village (used in the retirement village api).
 */
@property (strong, nonatomic) NSString *villageRegistration;

/**
 The number of current flatmates (used in the flatmates api).
 */
@property (nonatomic) NSInteger flatmates;

/**
 A description of the current flatmates (used in the flatmates api).
 */
@property (strong, nonatomic) NSString *currentFlatmates;

/*
 Display values (extracted from attributes)
 */
- (NSString *)location;
- (NSString *)roomsDisplay;
- (NSString *)petsAndSmokersDisplay;
- (NSString *)furnishingsDisplay;
- (NSString *)availableDisplay;
- (NSString *)inTheAreaDisplay;
- (NSString *)idealTenantDisplay;
- (NSString *)maximumTenantsDisplay;
- (NSString *)propertyPriceDisplay;

@end
