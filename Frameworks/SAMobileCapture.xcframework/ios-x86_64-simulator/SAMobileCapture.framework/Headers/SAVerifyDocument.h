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

@interface SAVerifyDocument : UIViewController

@property (strong, nonatomic, readwrite) NSString *navBarTitle;
@property (strong, nonatomic, readwrite) UIImage *sourceImage;
@property (nonatomic, assign) BOOL showProgress;
@property (nonatomic, assign) SAImageQuality imageQaulity;
@property (nonatomic, assign) SADocumentType documentType;
@property (nonatomic, assign) SAImageEnhancing imageEnchancing;
@property (nonatomic, assign) SAImageFilter imageFilter;
@property (nonatomic, assign) BOOL showIndicator;
@property (strong, nonatomic, readwrite) NSString *documentFileName;
@property (nonatomic, assign) SAImageFormat imageFormat;
@property (nonatomic, assign) CGFloat compressionQuality;
@property (nonatomic, assign) BOOL encryptFile;
@property (nonatomic, assign) SAClassificationItem classificatonItem;
@property (strong, nonatomic, readwrite) NSString *faceFileName;
@property (strong, nonatomic, readwrite) UIImage *faceImage;

- (instancetype)initWithBarcodeImage:(UIImage *)imageOfBarcode withBarcodeResult:(NSString *)resultOfBarcode withSecurityItems:(SASecurityItems *)itemsOfSecurity;

@end
