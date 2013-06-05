//
//  TMDTListingJob.h
//  TMAPIClient
//
//  Created by Nick Parfene on 25/05/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

#import "TMDTListing.h"

@class TMDTAgency;
@class TMDTJobApplicationDetails;

/**
 Represents a listing that contains job-specific information.
 
 For more information, see; http://developer.trademe.co.nz/api-reference/search-methods/jobs-search/
 */
@interface TMDTListingJob : TMDTListing

/**
 The type of position.
 */
@property (strong, nonatomic) NSString *jobType;

/**
 A description of the pay and benefits.
 */
@property (strong, nonatomic) NSString *payBenefits;

/**
 The reference for this position.
 */
@property (strong, nonatomic) NSString *positionReference;

@property (strong, nonatomic) NSString *applicationDetails;

/**
 Indicates whether a job permit is required for this position.
 */
@property (assign, nonatomic) BOOL isWorkPermitRequired;

/**
 Instructions on how the applicant should apply for this job.
 */
@property (strong, nonatomic) NSString *instructions;

/**
 The category for the position e.g. “Banking”.
 */
@property (strong, nonatomic) NSString *jobCategory;

/**
 The subcategory for the position e.g. “Tellers”.
 */
@property (strong, nonatomic) NSString *jobSubcategory;

/**
 The company the position is with.
 */
@property (strong, nonatomic) NSString *company;

/**
 The location of the position e.g. “Hurunui, Canterbury”.
 */
@property (strong, nonatomic) NSString *jobLocation;

/**
 The length of the contract (if the position is for a contractor).
 */
@property (strong, nonatomic) NSString *contractLength;

/**
 The payment type, contract etc.
 */
@property (strong, nonatomic) NSString *payType;

/**
 The ID of the job pack.
 */
@property (strong, nonatomic) NSString *jobPackId;

/**
 The agency this job was listed by.
 */
@property (strong, nonatomic) TMDTAgency *agency;

/**
 Contact and Apply Online details
 */
@property (strong, nonatomic) TMDTJobApplicationDetails *jobApplicationDetails;

@end
