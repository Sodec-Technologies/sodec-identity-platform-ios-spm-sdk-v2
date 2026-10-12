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

@interface SACounterConfig : NSObject

@property (nonatomic, assign) BOOL counterEnabled;
@property (strong, nonatomic, readwrite) UIColor *counterBackgroundColor;
@property (strong, nonatomic, readwrite) UIColor *counterContentColor;
@property (strong, nonatomic, readwrite) NSString *counterTitleFontFamily;
@property (nonatomic, assign) CGFloat counterTitleFontSize;
@property (nonatomic, assign) CGFloat counterCornerRadius;
@property (nonatomic, assign) NSTimeInterval counterDuration;

+ (SACounterConfig *)createCounterConfig;

@end
