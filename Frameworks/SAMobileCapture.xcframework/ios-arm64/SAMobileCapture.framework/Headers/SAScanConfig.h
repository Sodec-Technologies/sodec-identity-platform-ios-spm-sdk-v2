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

@interface SAScanConfig : NSObject

@property (strong, nonatomic, readwrite) UIColor *scanBackgroundColor;
@property (strong, nonatomic, readwrite) UIColor *scanRectangleLineColor;
@property (nonatomic, assign) CGFloat scanRectangleLineWidth;
@property (nonatomic, assign) CGFloat scanAngleSize;
@property (nonatomic, assign) CGFloat scanAngleLineWidth;
@property (strong, nonatomic, readwrite) UIColor *scanAngleColor;
@property (nonatomic, assign) BOOL scanLaserEnabled;
@property (nonatomic, assign) CGFloat scanLaserWidth;
@property (strong, nonatomic, readwrite) UIColor *scanLaserColor;
@property (strong, nonatomic, readwrite) UIColor *scanLaserShadowColor;

+ (SAScanConfig *)createScanConfig;

@end
