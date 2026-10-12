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

#define SA_SINGLE_PAGE_FILE_NAME @"sa_single"

@class SASinglePage;
@class SADetectDocument;
@class SAReadDocumentParams;
@class SAReadDocumentResult;

@protocol SASinglePageDelegate <NSObject>

@required
- (void)singlePageDidCancel:(SASinglePage *)controller;
- (void)singlePageDidClear:(SASinglePage *)controller;
- (void)singlePageDidDone:(SASinglePage *)controller withSinglePagePath:(NSString *)singlePagePath withIsEncrypted:(BOOL)isEncrypted withReadDocumentResult:(SAReadDocumentResult *)readDocumentResult;

@end

@interface SASinglePage : UIViewController
{
    id<SASinglePageDelegate> __unsafe_unretained delegate;
}

@property (unsafe_unretained) id<SASinglePageDelegate> delegate;
@property (strong, nonatomic, readwrite) NSString *singlePageNavBarTitle;
@property (strong, nonatomic, readwrite) NSString *folderNameForSinglePage;
@property (strong, nonatomic, readwrite) NSString *captureDescription;
@property (strong, nonatomic, readwrite) NSString *captureNavBarTitle;
@property (strong, nonatomic, readwrite) NSString *processNavBarTitle;
@property (strong, nonatomic, readwrite) NSString *verifyNavBarTitle;
@property (nonatomic, assign) BOOL showProgress;
@property (nonatomic, assign) BOOL showIndicator;
@property (strong, nonatomic, readwrite) SADetectDocument *detectDocument;
@property (nonatomic, assign) BOOL blurDetection;
@property (nonatomic, assign) SAImageEnhancing imageEnchancing;
@property (nonatomic, assign) BOOL encryptFile;
@property (strong, nonatomic, readwrite) SAReadDocumentParams *readDocumentParams;
@property (nonatomic, assign) BOOL parseBillDataOnCapture;

@end
