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

#import <SAMobileCapture/SADefineImage.h>

#define SA_FOLIO_PAGE_FILE_NAME @"sa_folio"

@class SAFolioPage;
@class SADetectDocument;
@class SAIdentityData;
@class SAIdentityTypes;

@protocol SAFolioPageDelegate <NSObject>

@required
- (void)folioPageDidCancel:(SAFolioPage *)controller;
- (void)folioPageDidClear:(SAFolioPage *)controller;
- (void)folioPageDidDone:(SAFolioPage *)controller withIdentityData:(SAIdentityData *)identityData withFrontPagePath:(NSString *)frontPagePath withBackPagePath:(NSString *)backPagePath withFolioPagePath:(NSString *)folioPagePath withIsEncrypted:(BOOL)isEncrypted;

@end

@interface SAFolioPage : UIViewController
{
    id<SAFolioPageDelegate> __unsafe_unretained delegate;
}

@property (unsafe_unretained) id<SAFolioPageDelegate> delegate;
@property (strong, nonatomic, readwrite) NSString *folioPageDescription;
@property (strong, nonatomic, readwrite) NSString *folioPageNavBarTitle;
@property (strong, nonatomic, readwrite) NSString *folderNameForFolioPage;
@property (strong, nonatomic, readwrite) NSString *frontCaptureDescription;
@property (strong, nonatomic, readwrite) NSString *frontCaptureNavBarTitle;
@property (strong, nonatomic, readwrite) NSString *frontProcessNavBarTitle;
@property (strong, nonatomic, readwrite) NSString *frontVerifyNavBarTitle;
@property (strong, nonatomic, readwrite) NSString *backCaptureNavBarTitle;
@property (strong, nonatomic, readwrite) NSString *backProcessNavBarTitle;
@property (strong, nonatomic, readwrite) NSString *backVerifyNavBarTitle;
@property (nonatomic, assign) BOOL showProgress;
@property (nonatomic, assign) BOOL showIndicator;
@property (strong, nonatomic, readwrite) SADetectDocument *detectDocument;
@property (nonatomic, assign) BOOL blurDetection;
@property (nonatomic, assign) BOOL classification;
@property (nonatomic, assign) BOOL faceDetection;
@property (nonatomic, assign) SAImageEnhancing imageEnchancing;
@property (nonatomic, assign) BOOL encryptFile;
@property (nonatomic, assign) BOOL showDocumentName;
@property (strong, nonatomic, readwrite) UIColor *documentNameBackgroundColor;
@property (strong, nonatomic, readwrite) NSString *desiredIdentityNumber;
@property (strong, nonatomic, readwrite) SAIdentityTypes *undesiredIdentityTypes;

@end
