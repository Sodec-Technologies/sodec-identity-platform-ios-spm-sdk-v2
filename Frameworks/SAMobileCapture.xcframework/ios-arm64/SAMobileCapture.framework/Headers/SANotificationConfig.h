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

@interface SANotificationConfig : NSObject

@property (strong, nonatomic, readwrite) UIColor *notificationBackgroundColor;
@property (strong, nonatomic, readwrite) UIColor *notificationIconColor;
@property (strong, nonatomic, readwrite) UIColor *notificationTextColor;
@property (strong, nonatomic, readwrite) NSString *notificationTitleFontFamily;
@property (strong, nonatomic, readwrite) NSString *notificationBodyFontFamily;
@property (nonatomic, assign) CGFloat notificationTitleFontSize;
@property (nonatomic, assign) CGFloat notificationBodyFontSize;
@property (nonatomic, assign) NSTimeInterval notificationDuration;
@property (nonatomic, assign) NSTimeInterval notificationDurationPositiveDeviation;
@property (nonatomic, assign) NSTimeInterval notificationDurationNegativeDeviation;
@property (nonatomic, assign) BOOL notificationShouldDismissOnClick;

+ (SANotificationConfig *)createNotificationConfig;

@end
