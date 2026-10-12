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
#import <SAMobileCapture/SADefineIdentity.h>

@class SAIdentityTypes;

@interface SAIdentityUtility : NSObject

+ (SAIdentityType)getIdentityType:(SAClassificationItem)classificationItem;
+ (NSString *)getNameOfDesiredIdentityTypes:(SAIdentityTypes *)undesiredIdentityTypes;
+ (BOOL)isUndesiredIdentityTypesValid:(SAIdentityTypes *)undesiredIdentityTypes;
+ (NSString *)getNameOfIdentityType:(SAIdentityType)idetityType;

@end
