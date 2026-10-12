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

@interface SACropConfig : NSObject

@property (strong, nonatomic, readwrite) UIColor *cropBackgroundColor;
@property (nonatomic, assign) CGFloat cropButtonSize;
@property (strong, nonatomic, readwrite) UIColor *cropButtonColor;
@property (strong, nonatomic, readwrite) UIColor *cropValidLineColor;
@property (strong, nonatomic, readwrite) UIColor *cropInvalidLineColor;
@property (strong, nonatomic, readwrite) UIColor *cropActiveButtonColor;
@property (nonatomic, assign) CGFloat cropLineWidth;
@property (strong, nonatomic, readwrite) UIColor *cropZoomBackgroundColor;
@property (nonatomic, assign) CGFloat cropZoomSize;
@property (nonatomic, assign) CGFloat cropZoomScale;
@property (strong, nonatomic, readwrite) UIColor *cropZoomBorderColor;
@property (nonatomic, assign) CGFloat cropZoomBorderWidth;

+ (SACropConfig *)createCropConfig;

@end
