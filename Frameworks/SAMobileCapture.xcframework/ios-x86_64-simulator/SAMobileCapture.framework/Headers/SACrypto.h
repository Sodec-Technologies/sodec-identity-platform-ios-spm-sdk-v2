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

@interface SACrypto : NSObject

+ (NSData *)encryptData:(NSData *)originalData;
+ (NSData *)decryptData:(NSData *)encryptedData;
+ (NSString *)encryptString:(NSString *)originalString;
+ (NSString *)decryptString:(NSString *)encryptedString;

@end
