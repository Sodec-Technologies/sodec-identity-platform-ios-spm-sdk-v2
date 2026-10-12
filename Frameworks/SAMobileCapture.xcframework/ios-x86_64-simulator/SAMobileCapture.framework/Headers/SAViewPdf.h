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

#import <SAMobileCapture/SASignDocument.h>

@class SAViewPdf;
@class SAViewPdfParams;
@class SASignDocumentParams;
@class SASignatureFields;
@class SABarcodeField;

NS_ASSUME_NONNULL_BEGIN

@protocol SAViewPdfDelegate <NSObject>

@required
- (void)onPdfDesign:(SAViewPdf *)controller withSignAndConfirmButton:(UIButton *)signAndConfirmButton;
- (void)onSignDesign:(SASignDocument *)controller withClearButton:(UIButton *)clearButton withCompleteButton:(UIButton *)completeButton;
- (void)viewPdfDidCancel:(SAViewPdf *)controller;
- (void)viewPdfDidError:(SAViewPdf *)controller withMessage:(NSString *)errorMessage;
- (void)viewPdfDidDone:(SAViewPdf *)controller;
- (void)viewPdfDidDone:(SAViewPdf *)controller withSignedPdfFilePath:(NSString *)signedPdfFilePath;

@end

@interface SAViewPdf : UIViewController
{
    id<SAViewPdfDelegate> __unsafe_unretained delegate;
}

@property (unsafe_unretained) id<SAViewPdfDelegate> delegate;
@property (strong, nonatomic, readwrite) SAViewPdfParams *viewPdfParams;
@property (strong, nonatomic, readwrite) SASignDocumentParams *signDocumentParams;

- (instancetype) init __attribute__((unavailable("use custom initializers")));
- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;

- (instancetype)initPdfFilePath:(nonnull NSString *)pdfFilePath withPdfPassword:(nullable NSString *)pdfPasswordOrNil;
- (instancetype)initPdfFilePath:(nonnull NSString *)pdfFilePath withPdfPassword:(nullable NSString *)pdfPasswordOrNil withSignatureFields:(nonnull SASignatureFields *)signatureFields;
- (instancetype)initPdfFilePath:(nonnull NSString *)pdfFilePath withPdfPassword:(nullable NSString *)pdfPasswordOrNil withSignatureFields:(nonnull SASignatureFields *)signatureFields withSignedPdfFileName:(nonnull NSString *)signedPdfFileName;

@end

NS_ASSUME_NONNULL_END
