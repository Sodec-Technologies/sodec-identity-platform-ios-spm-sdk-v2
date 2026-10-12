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

@interface SAAlertConfig : NSObject

@property (strong, nonatomic, readwrite) UIColor *alertViewTopColor;
@property (strong, nonatomic, readwrite) NSString *alertViewTopImage;
@property (strong, nonatomic, readwrite) UIColor *alertViewIndicatorColor;
@property (strong, nonatomic, readwrite) NSString *alertViewTitleFontFamily;
@property (nonatomic, assign) CGFloat alertViewTitleFontSize;
@property (strong, nonatomic, readwrite) UIColor *alertViewTitleTextColor;
@property (strong, nonatomic, readwrite) NSString *alertViewBodyFontFamily;
@property (nonatomic, assign) CGFloat alertViewBodyFontSize;
@property (strong, nonatomic, readwrite) UIColor *alertViewBodyTextColor;
@property (strong, nonatomic, readwrite) UIColor *alertViewPositiveButtonBackgroundColor;
@property (strong, nonatomic, readwrite) UIColor *alertViewNegativeButtonBackgroundColor;
@property (strong, nonatomic, readwrite) NSString *alertViewButtonsFontFamily;
@property (nonatomic, assign) CGFloat alertViewButtonsFontSize;
@property (strong, nonatomic, readwrite) UIColor *alertViewPositiveButtonTextColor;
@property (strong, nonatomic, readwrite) UIColor *alertViewNegativeButtonTextColor;
@property (nonatomic, assign) CGFloat alertViewButtonsCornerRadius;

+ (SAAlertConfig *)createAlertConfig;

@end
