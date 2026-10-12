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

@interface SAUIConfig : NSObject

@property (strong, nonatomic, readwrite) NSString *introImageName;
@property (nonatomic, strong, nullable) UIImage *introImage;
@property (strong, nonatomic, readwrite) UIColor *introButtonsTintColor;
@property (nonatomic, assign) CGFloat introButtonsCornerRadius;
@property (strong, nonatomic, readwrite) UIColor *primaryColor;
@property (strong, nonatomic, readwrite) UIColor *accentColor;
@property (strong, nonatomic, readwrite) UIColor *lightColor;
@property (strong, nonatomic, readwrite) UIColor *successColor;
@property (strong, nonatomic, readwrite) NSString *customStatusBarImage;
@property (strong, nonatomic, readwrite) NSString *customViewImage;
@property (strong, nonatomic, readwrite) NSString *customBottomBGImageForX;
@property (strong, nonatomic, readwrite) UIColor *statusBarColor;
@property (strong, nonatomic, readwrite) UIColor *navBarColor;
@property (strong, nonatomic, readwrite) UIColor *navBarTextColor;
@property (strong, nonatomic, readwrite) UIColor *viewColor;
@property (strong, nonatomic, readwrite) UIColor *toolBarColor;
@property (strong, nonatomic, readwrite) UIColor *bottomBGColorForX;
@property (strong, nonatomic, readwrite) UIColor *barTintColor;
@property (strong, nonatomic, readwrite) NSString *regularFont;
@property (strong, nonatomic, readwrite) NSString *boldFont;
@property (nonatomic, assign) BOOL barTranslucent;
@property (nonatomic, assign) CGFloat navBarTitleFontSize;
@property (nonatomic, assign) CGFloat barButtonItemTitleFontSize;
@property (nonatomic, assign) UIStatusBarStyle preferredStatusBarStyle;
@property (nonatomic, assign) BOOL refreshInViewDidAppear;

+ (SAUIConfig *)createUIConfig;

@end
