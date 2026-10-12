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

@interface SATipConfig : NSObject

@property (nonatomic, assign) BOOL tipEnabled;
@property (strong, nonatomic, readwrite) UIColor *tipBackgroundColor;
@property (strong, nonatomic, readwrite) UIColor *tipContentColor;
@property (strong, nonatomic, readwrite) NSString *tipFontFamily;
@property (nonatomic, assign) CGFloat tipFontSize;
@property (nonatomic, assign) CGFloat tipArrowWidth;
@property (nonatomic, assign) CGFloat tipArrowHeight;
@property (nonatomic, assign) CGFloat tipCornerRadius;
@property (strong, nonatomic, readwrite) UIColor *tipShadowColor;
@property (nonatomic, assign) CGFloat tipBubbleInset;
@property (nonatomic, assign) CGFloat tipTextInset;
@property (nonatomic, assign) NSTimeInterval tipDuration;
@property (nonatomic, assign) BOOL tipShouldDismissOnClick;

+ (SATipConfig *)createTipConfig;

@end
