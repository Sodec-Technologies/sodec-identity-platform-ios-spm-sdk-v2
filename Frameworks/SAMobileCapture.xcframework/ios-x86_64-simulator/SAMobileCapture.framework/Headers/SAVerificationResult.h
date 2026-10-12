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

@interface SAVerificationResult : NSObject

- (id)initWithDistance:(double)distance withIsIdentical:(BOOL)isIdentical;

@property (nonatomic, assign) double distance;
@property (nonatomic, assign) BOOL isIdentical;

- (NSDictionary *)toDictionary;
- (NSDictionary *)toDictionary:(int)currentCountOfAttempts withMaxCountOfAttempts:(int)maxCountOfAttempts;

@end
