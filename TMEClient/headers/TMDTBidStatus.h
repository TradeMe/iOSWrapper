//
//  TMDTBidStatus.h
//  TMAPIClient
//
//  Created by Peter Akuhata on 22/05/13.
//  Copyright (c) 2013 Trade Me. All rights reserved.
//

#ifndef TMAPIClient_TMDTBidResponseStatus_h
#define TMAPIClient_TMDTBidResponseStatus_h

/**
 The status of the Bid request.
 */
typedef NS_ENUM(NSInteger, TMDTBidStatus) {
    TMDTBidStatusSuccess = 0,                                         //-- The bid was a success.
    TMDTBidStatusReserveMet = 2,                                      //-- The reserve was met.
    TMDTBidStatusReserveNotMet = 4,                                   //-- The reserve was not met.
    TMDTBidStatusReserveMetAutoBidGreaterThanReserve = 6,             //-- The auto bid was higher than the reserve.
    TMDTBidStatusReserveMetAutoBidIncreased = 8,                      //-- The autobid was increased.
    TMDTBidStatusReserveNotMetAutoBid = 9,                            //-- An autobid did not met the reserve.
    TMDTBidStatusReserveMetExistingAutoBidGreaterThanBid = 10,        //-- Someone else has a higher bid which mets the reserve.
    TMDTBidStatusReserveNotMetExistingAutoBidGreaterThanBid = 12,     //-- Someone else has a higher bid and the reserve is not met.
    TMDTBidStatusReserveMetExistingAutoBidEqualToBid = 14,            //-- The reserve is met and the auto bids match.
    TMDTBidStatusReserveNotMetExistingAutoBidEqualToBid = 16,         //-- The reserve is not met and the auto bids match.
    TMDTBidStatusReserveMetAutoBid = 18,                              //-- The reserve is met by an auto bid.
    TMDTBidStatusNone = 1,                                            //-- The bid had some other error.
    TMDTBidStatusErrorAccountDisabled = 3,                            //-- The buyer account is disabled.
    TMDTBidStatusErrorBadMemberDetails = 5,                           //-- Not a member.
    TMDTBidStatusErrorProofOfGoods = 7,                               //-- Needs proof of goods.
    TMDTBidStatusErrorAuctionClosed = 9,                              //-- The auction is closed.
    TMDTBidStatusErrorOwnAuction = 11,                                //-- This is an auction owned by the member.
    TMDTBidStatusErrorBlacklisted = 13,                               //-- The member has been blacklisted by the seller.
    TMDTBidStatusErrorAuthenticatedMembersOnlyAuction = 15,           //-- The member needs to be authenticated to bid.
    TMDTBidStatusErrorAccountIndebt = 17,                             //-- The accountis in debt and can not bid.
    TMDTBidStatusErrorBidTooHigh = 19,                                //-- The bid is too high for our rules.
    TMDTBidStatusErrorBidLessThanMinimumNextBid = 21,                 //-- The bid is too low.
    TMDTBidStatusErrorBidLessThanFiftyCents = 23,                     //-- Bid needs to be hhigher than 50c.
    TMDTBidStatusErrorBidLessThanStartPrice = 25,                     //-- The bid must be greater than the start price.
    TMDTBidStatusErrorTooManyBids = 27,                               //-- There have been too many bids from the member in the last 24 hours.
    TMDTBidStatusErrorHasTopAutoBid = 29,                             //-- The member already has the top autobid.
    TMDTBidStatusErrorDatabase = 31,                                  //-- There was an error in the database.
    TMDTBidStatusErrorHasTopAutoBidCannotDecrease = 33,               //-- The auto bid top level cannot be decreased.
    TMDTBidStatusErrorListingAcceptsBuyNowOnly = 34,                  //-- Attempting to bid on a listing that can’t be bidded on.
    TMDTBidStatusErrorQuantityInvalid = 35,                           //-- Quantity is either less than 1 or greater than the maximum.
    TMDTBidStatusErrorListingIsAClassified = 36                       //-- Attempting to bid on a classified listing.
    
};

#endif
