//
//  TMEMemberDetailsViewController.h
//  TradeMeAPIClientSample
//
//  Created by Nick Parfene on 17/05/13.
//  Copyright (c) 2013 Trade Me. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TMEOAuthViewController.h"

@interface TMEMemberDetailsViewController : UIViewController<TMEOAuthViewControllerDelegate>

@property (weak, nonatomic) IBOutlet UILabel *labelNickname;

@end
