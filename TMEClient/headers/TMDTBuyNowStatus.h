//
//  TMDTBuyNowResponseStatus.h
//  TMAPIClient
//
//  Created by Peter Akuhata on 22/05/13.
//  Copyright (c) 2013 Trade Me. All rights reserved.
//

#ifndef TMAPIClient_TMDTBuyNowResponseStatus_h
#define TMAPIClient_TMDTBuyNowResponseStatus_h

/**
 The status of the Buy Now request.
*/
typedef NS_ENUM(NSInteger, TMDTBuyNowStatus) {
    TMDTBuyNowStatusSuccess = 0,                                      //-- The bid was a success.
    TMDTBuyNowStatusReserveMet = 2,                                   //-- The reserve was met.
    TMDTBuyNowStatusReserveNotMet = 4,                                //-- The reserve was not met.
    TMDTBuyNowStatusReserveMetAutoBidGreaterThanReserve = 6,          //-- The auto bid was higher than the reserve.
    TMDTBuyNowStatusReserveMetAutoBidIncreased = 8,                   //-- The autobid was increased.
    TMDTBuyNowStatusReserveNotMetAutoBid = 9,                         //-- An autobid did not met the reserve.
    TMDTBuyNowStatusReserveMetExistingAutoBidGreaterThanBid = 10,     //-- Someone else has a higher bid which mets the reserve.
    TMDTBuyNowStatusReserveNotMetExistingAutoBidGreaterThanBid = 12,  //-- Someone else has a higher bid and the reserve is not met.
    TMDTBuyNowStatusReserveMetExistingAutoBidEqualToBid = 14,         //-- The reserve is met and the auto bids match.
    TMDTBuyNowStatusReserveNotMetExistingAutoBidEqualToBid = 16,      //-- The reserve is not met and the auto bids match.
    TMDTBuyNowStatusReserveMetAutoBid = 18,                           //-- The reserve is met by an auto bid.
    TMDTBuyNowStatusNone = 1,                                         //-- The bid had some other error.
    TMDTBuyNowStatusErrorAccountDisabled = 3,                         //-- The buyer account is disabled.
    TMDTBuyNowStatusErrorBadMemberDetails = 5,                        //-- Not a member.
    TMDTBuyNowStatusErrorProofOfGoods = 7,                            //-- Needs proof of goods.
    TMDTBuyNowStatusErrorAuctionClosed = 9,                           //-- The auction is closed.
    TMDTBuyNowStatusErrorOwnAuction = 11,                             //-- This is an auction owed by the member.
    TMDTBuyNowStatusErrorBlacklisted = 13,                            //-- The member has been blacklisted by the seller.
    TMDTBuyNowStatusErrorAuthenticatedMembersOnlyAuction = 15,        //-- The member needs to be authenticated to bid.
    TMDTBuyNowStatusErrorAccountIndebt = 17,                          //-- The account is in debt and cannot bid.
    TMDTBuyNowStatusErrorBidTooHigh = 19,                             //-- The bid is too high for our rules.
    TMDTBuyNowStatusErrorBidLessThanMinimumNextBid = 21,              //-- The bid is too low.
    TMDTBuyNowStatusErrorBidLessThanFiftyCents = 23,                  //-- Bid needs to be higher than 50c.
    TMDTBuyNowStatusErrorBidLessThanStartPrice = 25,                  //-- The bid must be greater than the start price.
    TMDTBuyNowStatusErrorTooManyBids = 27,                            //-- There have been too many bids from the member in the last 24 hours.
    TMDTBuyNowStatusErrorHasTopAutoBid = 29,                          //-- The member already has the top autobid.
    TMDTBuyNowStatusErrorDatabase = 31,                               //-- There was an error in the database.
    TMDTBuyNowStatusErrorHasTopAutoBidCannotDecrease = 33,            //-- The auto bid top level cannot be decreased.
    TMDTBuyNowStatusErrorListingAcceptsTMDTBuyNowStatusOnly = 34,               //-- Attempting to bid on a listing that can’t be bidded on.
    TMDTBuyNowStatusErrorQuantityInvalid = 35,                        //-- Quantity is either less than 1 or greater than the maximum.
    TMDTBuyNowStatusErrorListingIsAClassified = 36                    //-- Attempting to bid on a classified listing.
};


#endif
