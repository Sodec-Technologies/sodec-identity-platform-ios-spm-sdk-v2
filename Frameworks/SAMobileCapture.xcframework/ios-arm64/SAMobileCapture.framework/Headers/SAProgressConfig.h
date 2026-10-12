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

@interface SAProgressConfig : NSObject

@property (strong, nonatomic, readwrite) UIColor *progressBackgroundColor;
@property (strong, nonatomic, readwrite) UIColor *progressContentColor;
@property (strong, nonatomic, readwrite) NSString *progressTitleFontFamily;
@property (strong, nonatomic, readwrite) NSString *progressBodyFontFamily;
@property (nonatomic, assign) CGFloat progressTitleFontSize;
@property (nonatomic, assign) CGFloat progressBodyFontSize;
@property (nonatomic, assign) CGFloat progressDIMValue;

+ (SAProgressConfig *)createProgressConfig;

@end
