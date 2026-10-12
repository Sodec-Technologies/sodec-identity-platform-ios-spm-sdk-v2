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

@class SASignDocument;
@class SASignDocumentParams;
@class SASignatureFields;

@protocol SASignDocumentDelegate <NSObject>

@required
- (void)onSignDesign:(SASignDocument *)controller withClearButton:(UIButton *)clearButton withCompleteButton:(UIButton *)completeButton;
- (void)signDocumentDidCancel:(SASignDocument *)controller;
- (void)signDocumentDidDone:(SASignDocument *)controller withSignedPdfFilePath:(NSString *)signedPdfFilePath;

@end

@interface SASignDocument : UIViewController
{
    id<SASignDocumentDelegate> __unsafe_unretained delegate;
}

@property (unsafe_unretained) id<SASignDocumentDelegate> delegate;
@property (strong, nonatomic, readwrite) NSString *pdfFilePath;
@property (strong, nonatomic, readwrite) SASignatureFields *signatureFields;
@property (strong, nonatomic, readwrite) NSString *signedPdfFileName;
@property (strong, nonatomic, readwrite) SASignDocumentParams *signDocumentParams;

@end
