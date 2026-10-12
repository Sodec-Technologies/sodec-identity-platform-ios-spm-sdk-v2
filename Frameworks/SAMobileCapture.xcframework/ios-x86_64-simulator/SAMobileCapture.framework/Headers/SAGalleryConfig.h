/*
 * Copyright (C) 2024 Sodec Apps Bilisim Teknolojileri, Inc - All rights reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Hasan Dertli <hasan.dertli@sodecapps.com>
 *
 * Sodec Apps Bilisim Teknolojileri
 * http://sodecapps.com
 * support@sodecapps.com
 */

@interface SAGalleryConfig : NSObject

@property (nonatomic, assign) BOOL galleryEnabled;
@property (nonatomic, assign) BOOL galleryShowLastKnownImage;
@property (strong, nonatomic, readwrite) UIColor *galleryBorderColor;
@property (nonatomic, assign) CGFloat galleryBorderWidth;
@property (nonatomic, assign) CGFloat galleryCornerRadius;
@property (nonatomic, assign) BOOL galleryForceBackButtonToUp;
@property (nonatomic, assign) BOOL synchronousRequest;

+ (SAGalleryConfig *)createGalleryConfig;

@end
