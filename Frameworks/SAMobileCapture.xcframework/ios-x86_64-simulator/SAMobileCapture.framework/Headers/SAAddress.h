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

@interface SAAddress : NSObject

- (id)initWithProvince:(NSString *)province withDistrict:(NSString *)district withNeighborhood:(NSString *)neighborhood withStreet:(NSString *)street withOuterDoorNo:(NSString *)outerDoorNo withInnerDoorNo:(NSString *)innerDoorNo;

@property (strong, nonatomic, readonly) NSString *province;
@property (strong, nonatomic, readonly) NSString *district;
@property (strong, nonatomic, readonly) NSString *neighborhood;
@property (strong, nonatomic, readonly) NSString *street;
@property (strong, nonatomic, readonly) NSString *outerDoorNo;
@property (strong, nonatomic, readonly) NSString *innerDoorNo;

- (NSDictionary *)toDictionary;

@end
