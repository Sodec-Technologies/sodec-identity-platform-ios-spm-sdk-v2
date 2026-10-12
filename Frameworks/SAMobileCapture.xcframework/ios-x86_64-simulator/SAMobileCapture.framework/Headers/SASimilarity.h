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

@interface SASimilarity : NSObject

+ (double)levenshteinSimilarity:(NSString *)leftString withRight:(NSString *)rightString;
+ (double)damerauLevenshteinSimilarity:(NSString *)leftString withRight:(NSString *)rightString;
+ (double)longestCommonSubsequenceSimilarity:(NSString *)leftString withRight:(NSString *)rightString;

@end
