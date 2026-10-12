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

@interface SAIndicatorConfig : NSObject

@property (strong, nonatomic, readwrite) UIColor *indicatorColor;
@property (strong, nonatomic, readwrite) UIColor *indicatorBackgroundColor;
@property (nonatomic, assign) CGFloat indicatorSize;
@property (nonatomic, assign) CGFloat indicatorCornerRadius;
@property (nonatomic, assign) CGFloat indicatorDIMValue;

+ (SAIndicatorConfig *)createIndicatorConfig;

@end
