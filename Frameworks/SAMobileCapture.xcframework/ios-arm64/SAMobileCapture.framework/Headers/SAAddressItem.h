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

@interface SAAddressItem : NSObject

- (id)initWithProvice:(NSString *)province withDistricts:(NSArray *)districts;

@property (strong, nonatomic, readonly) NSString *province;
@property (strong, nonatomic, readonly) NSArray *districts;

@end
