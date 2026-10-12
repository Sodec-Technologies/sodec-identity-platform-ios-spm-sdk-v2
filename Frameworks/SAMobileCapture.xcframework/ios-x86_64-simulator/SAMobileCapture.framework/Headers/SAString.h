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

@class SADeasciifier;
@class SADate;

@interface SAString : NSObject

+ (BOOL)isEmpty:(NSString *)string;
+ (BOOL)isEmptySpace:(NSString *)string;
+ (BOOL)isNumeric:(NSString *)string;
+ (BOOL)isNumericSpace:(NSString *)string;
+ (BOOL)isAlpha:(NSString *)string;
+ (BOOL)isAlphaSpace:(NSString *)string;
+ (BOOL)isAlphaNumeric:(NSString *)string;
+ (BOOL)isAlphaNumericSpace:(NSString *)string;
+ (NSString *)toLowerCaseStringWithEnglish:(NSString *)string;
+ (NSString *)toUpperCaseStringWithEnglish:(NSString *)string;
+ (NSString *)toLowerCaseStringWithTurkish:(NSString *)string;
+ (NSString *)toUpperCaseStringWithTurkish:(NSString *)string;
+ (NSString *)deleteWhitespace:(NSString *)string;
+ (NSString *)getChar:(NSString *)string atIndex:(NSUInteger)index;

+ (NSString *)handleWithNumbersInLowerCaseString:(NSString *)lowerCaseString;
+ (NSString *)handleWithLettersInLowerCaseString:(NSString *)lowerCaseString;
+ (NSString *)handleWithSerialNumber:(NSString *)serialNumber withNewIdentity:(BOOL)newIdentity;
+ (BOOL)isSerialNumberValid:(NSString *)serialNumber;
+ (BOOL)isIdentityNumberValid:(NSString *)identityNumber;
+ (NSString *)maskIdentityNumber:(NSString *)identityNumber;
+ (NSString *)adjustText:(NSString *)text withDeasciifier:(SADeasciifier *)deasciifier;
+ (NSString *)normalizeText:(NSString *)text;
+ (SADate *)adjustDateOfBirthAsDate:(NSString *)birthDate;
+ (SADate *)adjustDateOfPaymentAsDate:(NSString *)paymentDate;
+ (SADate *)adjustTurkishDateAsDate:(NSString *)turkishDate;

+ (BOOL)isDayValid:(int)day;
+ (BOOL)isMonthValid:(int)month;
+ (BOOL)isYearValid:(int)year;

@end
