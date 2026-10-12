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

@interface SASignDocumentParams : NSObject

- (id)init;

@property (strong, nonatomic, readwrite) UIColor *signPadColor;
@property (strong, nonatomic, readwrite) NSString *buttonFontFamily;
@property (nonatomic, assign) CGFloat buttonFontSize;
@property (strong, nonatomic, readwrite) NSString *clearButtonTitle;
@property (strong, nonatomic, readwrite) UIColor *clearButtonEnabledBackgroundColor;
@property (strong, nonatomic, readwrite) UIColor *clearButtonEnabledTextColor;
@property (strong, nonatomic, readwrite) UIColor *clearButtonDisabledBackgroundColor;
@property (strong, nonatomic, readwrite) UIColor *clearButtonDisabledTextColor;
@property (strong, nonatomic, readwrite) NSString *completeButtonTitle;
@property (strong, nonatomic, readwrite) UIColor *completeButtonEnabledBackgroundColor;
@property (strong, nonatomic, readwrite) UIColor *completeButtonEnabledTextColor;
@property (strong, nonatomic, readwrite) UIColor *completeButtonDisabledBackgroundColor;
@property (strong, nonatomic, readwrite) UIColor *completeButtonDisabledTextColor;
@property (strong, nonatomic, readwrite) UIColor *descriptionLabelTextColor;
@property (strong, nonatomic, readwrite) NSString *descriptionLabelFontFamily;
@property (nonatomic, assign) CGFloat descriptionLabelFontSize;
@property (strong, nonatomic, readwrite) UIColor *agreementLabelTextColor;
@property (strong, nonatomic, readwrite) NSString *agreementLabelFontFamily;
@property (nonatomic, assign) CGFloat agreementLabelFontSize;
@property (strong, nonatomic, readwrite) NSString *agreementLabelText;
@property (strong, nonatomic, readwrite) UIColor *lineColor;
@property (strong, nonatomic, readwrite) UIColor *cancelButtonColor;
@property (strong, nonatomic, readwrite) UIColor *signatureColor;
@property (strong, nonatomic, readwrite) NSString *invalidSignatureMessage;
@property (nonatomic, assign) UIStatusBarStyle preferredStatusBarStyle;

@end
