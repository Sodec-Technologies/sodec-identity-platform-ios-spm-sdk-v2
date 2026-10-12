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

@interface SAConfigManager : NSObject

- (id)init;

@property (nonatomic, assign) BOOL debuggable;
@property (strong, nonatomic, readwrite) NSString *language;
@property (strong, nonatomic, readwrite) NSString *introImageName;
/**
 * Intro ekranında gösterilecek görsel (UIImage).
 * Ayarlanırsa @c introImageName değerine göre önceliklidir.
 * Demo uygulamasında galeri seçiminden set edilir.
 */
@property (nonatomic, strong, nullable) UIImage *introImage;
@property (strong, nonatomic, readwrite) UIColor *introButtonsTintColor;
@property (nonatomic, assign) CGFloat introButtonsCornerRadius;
@property (strong, nonatomic, readwrite) UIColor *primaryColor;
@property (strong, nonatomic, readwrite) UIColor *accentColor;
@property (strong, nonatomic, readwrite) UIColor *lightColor;
@property (strong, nonatomic, readwrite) UIColor *barColor;
@property (strong, nonatomic, readwrite) UIColor *barTintColor;
@property (strong, nonatomic, readwrite) UIColor *successColor;
@property (strong, nonatomic, readwrite) UIColor *warningColor;
@property (nonatomic, assign) UIStatusBarStyle statusBarStyle;
@property (nonatomic, assign) BOOL barTranslucent;
@property (strong, nonatomic, readwrite) NSString *regularFontName;
@property (strong, nonatomic, readwrite) NSString *boldFontName;
@property (strong, nonatomic, readwrite) UIColor *positiveButtonBackgroundColor;
@property (strong, nonatomic, readwrite) UIColor *negativeButtonBackgroundColor;
@property (strong, nonatomic, readwrite) UIColor *positiveButtonTextColor;
@property (strong, nonatomic, readwrite) UIColor *negativeButtonTextColor;
@property (nonatomic, assign) CGFloat buttonsCornerRadius;
@property (strong, nonatomic, readwrite) UIColor *cropperTintColor;

- (void)applyAndSaveChanges;

@end
