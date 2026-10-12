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

@interface SAStepperConfig : NSObject

@property (strong, nonatomic, readwrite) UIColor *stepperCircleColor;
@property (strong, nonatomic, readwrite) UIColor *stepperIndicatorColor;
@property (strong, nonatomic, readwrite) UIColor *stepperLineColor;
@property (strong, nonatomic, readwrite) UIColor *stepperLineDoneColor;
@property (strong, nonatomic, readwrite) UIColor *stepperNumberColor;
@property (strong, nonatomic, readwrite) NSString *stepperNumberFontFamily;
@property (nonatomic, assign) CGFloat stepperNumberFontSize;
@property (strong, nonatomic, readwrite) UIColor *stepperDescriptionColor;
@property (strong, nonatomic, readwrite) NSString *stepperDescriptionFontFamily;
@property (nonatomic, assign) CGFloat stepperDescriptionFontSize;

+ (SAStepperConfig *)createStepperConfig;

@end
