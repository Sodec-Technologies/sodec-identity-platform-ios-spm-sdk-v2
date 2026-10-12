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

@interface SAToastConfig : NSObject

@property (strong, nonatomic, readwrite) UIColor *toastBackgroundColor;
@property (strong, nonatomic, readwrite) NSString *toastTitleFontFamily;
@property (strong, nonatomic, readwrite) NSString *toastBodyFontFamily;
@property (nonatomic, assign) CGFloat toastTitleFontSize;
@property (nonatomic, assign) CGFloat toastBodyFontSize;
@property (strong, nonatomic, readwrite) UIColor *toastTitleTextColor;
@property (strong, nonatomic, readwrite) UIColor *toastBodyTextColor;
@property (nonatomic, assign) NSTimeInterval toastDuration;
@property (nonatomic, assign) BOOL toastShouldDismissOnClick;

+ (SAToastConfig *)createToastConfig;

@end
