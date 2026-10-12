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

@class SACropDocument;
@class SADetectDocument;
@class SAClassifyDocument;

@protocol SACropDocumentDelegate <NSObject>

@required
- (void)cropDocumentDidCancel:(SACropDocument *)controller;
- (void)cropDocumentDidDone:(SACropDocument *)controller withCroppedImage:(UIImage *)croppedImage;

@end

@interface SACropDocument : UIViewController
{
    id<SACropDocumentDelegate> __unsafe_unretained delegate;
}

@property (unsafe_unretained) id<SACropDocumentDelegate> delegate;
@property (strong, nonatomic, readwrite) NSString *navBarTitle;
@property (strong, nonatomic, readwrite) UIImage *sourceImage;
@property (nonatomic, assign) BOOL showProgress;
@property (nonatomic, assign) BOOL showIndicator;
@property (nonatomic, assign) BOOL borderFromTextBounds;
@property (strong, nonatomic, readwrite) SADetectDocument *detectDocument;
@property (nonatomic, assign) double blurScore;

@end
