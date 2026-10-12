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

NS_ASSUME_NONNULL_BEGIN

/**
 * Public Objective-C representation of photocopy detection result.
 *
 * isOriginal == YES  -> predicted as original document
 * isOriginal == NO   -> predicted as photocopy
 *
 * originalityScore   -> percentage in [0..100]
 * bwPhotocopyScore   -> black-and-white photocopy score in [0..100]
 */
@interface SAPhotocopyDetectionResult : NSObject

- (instancetype)initWithIsOriginal:(BOOL)isOriginal
                 originalityScore:(float)originalityScore
               bwPhotocopyScore:(float)bwPhotocopyScore;

/** YES if predicted as original; NO if predicted as photocopy. */
@property (nonatomic, assign, readwrite) BOOL isOriginal;

/** Originality score as percentage in [0..100]. */
@property (nonatomic, assign, readwrite) float originalityScore;

/** Black-and-white photocopy score as percentage in [0..100]. */
@property (nonatomic, assign, readwrite) float bwPhotocopyScore;

/**
 * Default "empty" result:
 * isOriginal = NO, originalityScore = 0.0, bwPhotocopyScore = 0.0
 */
+ (instancetype)emptyResult;

/**
 * Serializes the result into a dictionary:
 * {
 *   "isOriginal":        NSNumber(bool),
 *   "originalityScore":  NSNumber(float),
 *   "bwPhotocopyScore":  NSNumber(float)
 * }
 */
- (NSDictionary *)toDictionary;

@end

NS_ASSUME_NONNULL_END
