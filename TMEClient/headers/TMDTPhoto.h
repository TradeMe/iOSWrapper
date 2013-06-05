//
//  TMDTPhoto.h
//  TMAPIClient
//
//  Created by Nick Parfene on 4/07/12.
//  Copyright (c) 2012 Trade Me. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Contains information about a photo.
 */
@interface TMDTPhoto : NSObject

/**
 Returns the photo ID.
 */
@property (strong, nonatomic) NSNumber *photoId;

/**
 Returns the url for the photo at 'plus' size.
 */
@property (strong, nonatomic) NSString *plusSizeUrl;

/**
 Returns the url for the photo at full size.
 */
@property (strong, nonatomic) NSString *fullSizeUrl;

/**
 Returns the url for the photo to be used in a gallery.
 */
@property (strong, nonatomic) NSString *galleryUrl;

/**
 Returns the url for a large sized version of the photo.
 */
@property (strong, nonatomic) NSString *largeUrl;

/**
 Returns the url for the photo sized to be used in a list view
 */
@property (strong, nonatomic) NSString *listUrl;

/**
 Returns the url for a medium sized version of the photo.
 */
@property (strong, nonatomic) NSString *mediumUrl;

/**
 Returns the url for a thumbnail sized version of the photo.
 */
@property (strong, nonatomic) NSString *thumbnailUrl;

/**
 Create an instance of this class passing through data from a dictionary
 */
- (id)initWithDictionary:(NSDictionary *)dictionaryOfPhotoInformation;

@end
