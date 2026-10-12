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

#import <SAMobileCapture/SADefineClassification.h>

@interface SAClassifyDocument : NSObject

@property (nonatomic, assign) BOOL enabled;
@property (nonatomic, assign) SAClassificationItem queryItem;
@property (nonatomic, assign) int accuracyScore;

@end
