//
//  TMDTQuestionAnswer.h
//  TMAPIClient
//
//  Created by Nick Parfene on 4/07/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

@class TMDTMember;

/**
 Represents a question that was asked from a buyer, and then answer that was given by the seller.
 */
@interface TMDTQuestionAnswer : NSObject

/**
 The question ID.
 */
@property (strong, nonatomic) NSNumber *listingQuestionId;

/**
 The text of the question.
 */
@property (strong, nonatomic) NSString *comment;

/**
 The date and time the question was asked.
 */
@property (strong, nonatomic) NSDate *commentDate;

/**
 The answer given to the question by the owner of the listing.
 */
@property (strong, nonatomic) NSString *answer;

/**
 The date the question was answered.
 */
@property (strong, nonatomic) NSDate *answerDate;

/**
 Indicates whether this is a comment from the seller rather than a question.
 */
@property (assign, nonatomic) BOOL isSellerComment;

/**
 The member details for the member asking the question.
 */
@property (strong, nonatomic) TMDTMember *askingMember;

- (id)initWithDictionary:(NSDictionary *)dictionaryOfQuestionAnswer;

@end
