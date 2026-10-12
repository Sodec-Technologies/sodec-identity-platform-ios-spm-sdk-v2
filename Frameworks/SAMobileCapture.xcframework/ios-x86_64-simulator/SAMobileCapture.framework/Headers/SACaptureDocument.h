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
#import <SAMobileCapture/SADefineDocument.h>
#import <SAMobileCapture/SADefineClassification.h>
#import <SAMobileCapture/SASecurityItems.h>

@class SACaptureDocument;
@class SADetectDocument;
@class SAClassifyDocument;
@class SAReadDocumentParams;
@class SAIdentityTypes;

@protocol SACaptureDocumentDelegate <NSObject>

@required
- (void)captureDocumentDidCancel:(SACaptureDocument *)controller;
- (void)captureDocumentDidDone:(SACaptureDocument *)controller withDocumentPath:(NSString *)documentPath withIsEncrypted:(BOOL)isEncrypted withClassificationItem:(SAClassificationItem)classificationItem withBarcodeImage:(UIImage *)barcodeImage withBarcodeResult:(NSString *)barcodeResult withSecurityItems:(SASecurityItems *)securityItems;

@end

@interface SACaptureDocument : UIViewController
{
    id<SACaptureDocumentDelegate> __unsafe_unretained delegate;
}

@property (unsafe_unretained) id<SACaptureDocumentDelegate> delegate;
@property (strong, nonatomic, readwrite) NSString *captureDescription;
@property (strong, nonatomic, readwrite) NSString *captureNavBarTitle;
@property (strong, nonatomic, readwrite) NSString *processNavBarTitle;
@property (strong, nonatomic, readwrite) NSString *verifyNavBarTitle;
@property (nonatomic, assign) BOOL showProgress;
@property (nonatomic, assign) BOOL showIndicator;
@property (strong, nonatomic, readwrite) SADetectDocument *detectDocument;
@property (nonatomic, assign) double blurScore;
@property (strong, nonatomic, readwrite) SAClassifyDocument *classifyDocument;
@property (nonatomic, assign) BOOL faceDetection;
@property (nonatomic, assign) SAImageQuality imageQaulity;
@property (nonatomic, assign) SADocumentType documentType;
@property (nonatomic, assign) SAImageEnhancing imageEnchancing;
@property (nonatomic, assign) SAImageFilter imageFilter;
@property (strong, nonatomic, readwrite) NSString *documentFileName;
@property (nonatomic, assign) SAImageFormat imageFormat;
@property (nonatomic, assign) CGFloat compressionQuality;
@property (nonatomic, assign) BOOL encryptFile;
@property (strong, nonatomic, readwrite) NSString *desiredIdentityNumber;
@property (strong, nonatomic, readwrite) NSString *faceFileName;
@property (nonatomic, assign) BOOL parseBillData;
@property (strong, nonatomic, readwrite) SAReadDocumentParams *readDocumentParams;
@property (strong, nonatomic, readwrite) SAIdentityTypes *undesiredIdentityTypes;
@property (nonatomic, assign) BOOL enableServerModelForIDCardVerification;

@end
