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

#import <SAMobileCapture/SADefineSwipe.h>

@interface SAViewPdfParams : NSObject

- (id)init;

@property (strong, nonatomic, readwrite) NSString *navBarTitle;
@property (strong, nonatomic, readwrite) UIColor *backgroundColor;
@property (strong, nonatomic, readwrite) UIColor *buttonEnabledBackgroundColor;
@property (strong, nonatomic, readwrite) UIColor *buttonEnabledTextColor;
@property (strong, nonatomic, readwrite) UIColor *buttonDisabledBackgroundColor;
@property (strong, nonatomic, readwrite) UIColor *buttonDisabledTextColor;
@property (strong, nonatomic, readwrite) NSString *buttonFontFamily;
@property (nonatomic, assign) CGFloat buttonFontSize;
@property (strong, nonatomic, readwrite) UIColor *buttonBackgroundViewColor;
@property (strong, nonatomic, readwrite) UIColor *buttonBottomSafeAreaViewColor;
@property (nonatomic, assign) CGFloat buttonHeight;
@property (nonatomic, assign) CGFloat buttonMarginTop;
@property (nonatomic, assign) CGFloat buttonMarginBottom;
@property (nonatomic, assign) CGFloat buttonMarginLeft;
@property (nonatomic, assign) CGFloat buttonMarginRight;
@property (strong, nonatomic, readwrite) NSString *signButtonTitle;
@property (strong, nonatomic, readwrite) NSString *confirmButtonTitle;
@property (strong, nonatomic, readwrite) UIColor *infoLabelBackgroundColor;
@property (strong, nonatomic, readwrite) UIColor *infoLabelTextColor;
@property (strong, nonatomic, readwrite) NSString *infoLabelFontFamily;
@property (nonatomic, assign) CGFloat infoLabelFontSize;
@property (strong, nonatomic, readwrite) NSString *tipMessage;
@property (nonatomic, assign) SASwipeType swipeType;

@end
