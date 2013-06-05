//
//  TMEMemberDetailsViewController.m
//  TradeMeAPIClientSample
//
//  Created by Nick Parfene on 17/05/13.
//  Copyright (c) 2013 Trade Me. All rights reserved.
//

#import "TMEMemberDetailsViewController.h"
#import "TMDTMemberSummaryResponse.h"
#import "TMEOAuthViewController.h"

@interface TMEMemberDetailsViewController ()

@property (strong, nonatomic) TMDTMemberSummaryResponse *memberSummary;

@property (weak, nonatomic) IBOutlet UIButton *buttonLogout;
@property (weak, nonatomic) IBOutlet UIButton *buttonTryAgain;

- (IBAction)touchedButtonTryAgain:(UIButton *)sender;
- (IBAction)touchedButtonLogout:(UIButton *)sender;

@end

@implementation TMEMemberDetailsViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

#pragma mark - View lifecycle

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.title = @"Trade Me API Sample";

    self.buttonLogout.hidden = YES;
    self.buttonTryAgain.hidden = YES;
    
    self.labelNickname.text = @"...";
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    
    if ([[TMEClient sharedInstance].client canSignRequest]) {
        //-- register for Token Notifications (expired tokens)
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleOAuth:) name:TMEOAuthFailedWithTokenInvalidNotification object:nil];

        [self fetchMemberProfile];
    }
    else {
        //-- begin the OAuth flow
        [self handleOAuth:nil];
    }
}

- (void)viewDidDisappear:(BOOL)animated
{
    [super viewDidDisappear:animated];
    
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}

- (void)configureView
{
    self.labelNickname.text = self.memberSummary.nickname;
}

#pragma mark - Fetch member details
- (void)fetchMemberProfile
{
    [[TMEClient sharedInstance] getMemberSummaryWithCompletion:^(TMDTMemberSummaryResponse *memberSummary, NSError *error) {
        if (error) {
            [self showTryAgain];
        }
        else {
            [self showLogout];
        }
        
        self.memberSummary = memberSummary;
        [self configureView];
    }];
}

- (void)showLogout
{
    self.buttonTryAgain.hidden = YES;
    self.buttonLogout.hidden = NO;
}

- (void)showTryAgain
{
    self.buttonTryAgain.hidden = NO;
    self.buttonLogout.hidden = YES;
}


#pragma mark - TMEOAuthViewController delegate
- (void)handleOAuth:(NSNotification *)notification
{
    TMEOAuthViewController *oauthViewController = [[TMEOAuthViewController alloc] initWithNibName:NSStringFromClass([TMEOAuthViewController class]) bundle:nil];
    oauthViewController.delegate = self;
    [self presentViewController:oauthViewController animated:YES completion:^{
        NSLog(@"Finished with the OAuth View Controller");
    }];
}

- (void)oAuthViewControllerDidLogin
{
    [self fetchMemberProfile];
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)oAuthViewController:(TMEOAuthViewController *)tmeAuthViewController didFailToLoginWithError:(NSError *)error
{
    //-- need to handle errors that have occurred during the login process
    NSLog(@"Error %@", error);
    
    [self dismissViewControllerAnimated:YES completion:nil];
    [self showTryAgain];
}

- (IBAction)touchedButtonTryAgain:(UIButton *)sender
{
    [[TMEClient sharedInstance] logout];
    [self handleOAuth:nil];
}

- (IBAction)touchedButtonLogout:(UIButton *)sender
{
    [[TMEClient sharedInstance] logout];
    [self handleOAuth:nil];
}
@end
