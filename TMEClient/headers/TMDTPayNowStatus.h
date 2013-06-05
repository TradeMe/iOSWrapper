//
//  TMDTPayNowStatus.h
//  TMAPIClient
//
//  Created by Peter Akuhata on 14/02/13.
//  Copyright (c) 2013 Trade Me. All rights reserved.
//

#ifndef TMAPIClient_TMDTPayNowStatus_h
#define TMAPIClient_TMDTPayNowStatus_h

/**
 If something went wrong with the Pay Now request, this enumeration contains a status code that indicates exactly what went wrong. When there are multiple errors, this is the status code for the first error.
*/
typedef NS_ENUM(NSInteger, TMDTPayNowStatus) {
    /**
     The operation was successful.
     */
    TMDTPayNowStatusSuccess = 0,
    
    /**
     The provided purchase ID is invalid.
     */
    TMDTPayNowStatusPurchaseNotFound = 10001,
    
    /**
     The provided auction ID is invalid.
     */
    TMDTPayNowStatusAuctionNotFound = 1,
    
    /**
     The provided offer ID is invalid.
     */
    TMDTPayNowStatusOfferNotFound = 2,
    
    /**
     In order to pay, the authenticated member must be the winner of the auction.
     */
    TMDTPayNowStatusBuyerNotTheWinner = 3,
    
    /**
     A payment has already been made for the auction.
     */
    TMDTPayNowStatusPaymentAlreadyMade = 4,
    
    /**
     The buyer cannot pay with credit card because they are not authenticated.
     */
    TMDTPayNowStatusBuyerNotAuthenticated = 5,
    
    /**
     The seller's Pay Now account has been temporarily suspended.
     */
    TMDTPayNowStatusSellerSuspended = 6,
    
    /**
     The seller does not have a Pay Now account.
     */
    TMDTPayNowStatusUnauthorisedSeller = 7,
    
    /**
     There is a problem with the shipping options for the auction.
     */
    TMDTPayNowStatusUnknownShipping = 8,
    
    /**
     The buyer cannot purchase this item as it would cause them to exceed their daily limit on Pay Now purchases.
     */
    TMDTPayNowStatusExceededPurchaseLimit = 9,
    
    /**
     The payment cannot be processed because the payment gateways are all currently unavailable. Try again later.
     */
    TMDTPayNowStatusPaymentProvidersDown = 10,
    
    /**
     The buyer's account is under investigation. Because of this, no credit card purchases can be made at the current time.
     */
    TMDTPayNowStatusBuyerUnderInvestigation = 11,
    
    /**
     The payment was blocked because our automated fraud checking algorithm determined the payment to be potentially fraudulent.
     */
    TMDTPayNowStatusSuspiciousPayment = 12,
    
    /**
     The provided delivery ID is invalid.
     */
    TMDTPayNowStatusInvalidDeliveryId = 13,
    
    /**
     The provided cardholder name is invalid.
     */
    TMDTPayNowStatusInvalidCardholderName = 14,
    
    /**
     The provided credit card number is invalid.
     */
    TMDTPayNowStatusInvalidCardNumber = 16,
    
    /**
     The provided expiry date is invalid.
     */
    TMDTPayNowStatusInvalidExpiryDate = 17,
    
    /**
     The provided CVV code is invalid.
     */
    TMDTPayNowStatusInvalidCvv = 18,
    
    /**
     The provided phone number is invalid.
     */
    TMDTPayNowStatusInvalidPhoneNumber = 19,
    
    /**
     The card type is not supported for this item. For example, for age verification reasons Prezzy Cards cannot be used to buy wine.
     */
    TMDTPayNowStatusCardTypeFailure = 20,
    
    /**
     Saved credit card details cannot be used, either because no saved details exist or because we do not allow the use of these details for this particular item.
     */
    TMDTPayNowStatusProblemWithSavedCreditCard = 21,
    
    /**
     The credit card transaction was declined by the cardholder's bank.
     */
    TMDTPayNowStatusPaymentDeclined = 22,
    
    /**
     The payment provided failed to process the transaction. Try again later.
     */
    TMDTPayNowStatusPaymentProviderFailure = 23,
    
    /**
     The transaction was successful, but there was an error while sending the confirmation emails.
     */
    TMDTPayNowStatusFailedToSendEmails = 24
};

#endif
