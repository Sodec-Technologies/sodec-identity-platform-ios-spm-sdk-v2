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

#import <SAMobileCapture/SADefineIdentity.h>

@class SADate;
@class SASecurityItems;
@class SAPhotocopyDetectionResult;

@interface SAIdentityData : NSObject

@property (strong, nonatomic, readwrite) NSString *facePath;
@property (nonatomic, assign) BOOL isEncrypted;
@property (nonatomic, assign) SAIdentityType identityType;
@property (strong, nonatomic, readwrite) NSString *identityNumber;
@property (strong, nonatomic, readwrite) NSString *firstName;
@property (strong, nonatomic, readwrite) NSString *lastName;
@property (strong, nonatomic, readwrite) SADate *dateOfBirth;
@property (strong, nonatomic, readwrite) NSString *serialNumber;
@property (strong, nonatomic, readwrite) NSString *fatherName;
@property (strong, nonatomic, readwrite) NSString *motherName;
@property (strong, nonatomic, readwrite) SADate *issueDate;
@property (strong, nonatomic, readwrite) SADate *expirationDate;
@property (strong, nonatomic, readwrite) NSString *issuingCountry;
@property (strong, nonatomic, readwrite) NSString *nationality;

- (NSDictionary *)toDictionary:(SASecurityItems *)securityItems withFrontPhotocopyDetectionResult:(SAPhotocopyDetectionResult *)frontPhotocopyDetectionResult withBackPhotocopyDetectionResult:(SAPhotocopyDetectionResult *)backPhotocopyDetectionResult;

@end
