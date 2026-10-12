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

@class SADate;
@class SAAddress;

@interface SACustomerData : NSObject

@property (strong, nonatomic, readwrite) SADate *dateOfBirth;
@property (strong, nonatomic, readwrite) SADate *dateOfExpiry;
@property (strong, nonatomic, readwrite) NSString *nameOfFather;
@property (strong, nonatomic, readwrite) NSString *name;
@property (strong, nonatomic, readwrite) NSString *identityNo;
@property (strong, nonatomic, readwrite) NSString *identityType;
@property (strong, nonatomic, readwrite) SADate *dateOfIssue;
@property (strong, nonatomic, readwrite) NSString *surname;
@property (strong, nonatomic, readwrite) NSString *nameOfMother;
@property (strong, nonatomic, readwrite) NSString *documentNo;
@property (strong, nonatomic, readwrite) NSString *gender;
@property (strong, nonatomic, readwrite) NSString *nationality;
@property (strong, nonatomic, readwrite) NSString *issuingCountry;

- (NSDictionary *)toDictionary:(SAAddress *)address;

@end
