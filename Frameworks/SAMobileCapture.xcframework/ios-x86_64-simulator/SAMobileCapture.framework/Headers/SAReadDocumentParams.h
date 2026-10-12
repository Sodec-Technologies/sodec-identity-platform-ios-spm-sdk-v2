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

#import <SAMobileCapture/SADefineCapture.h>
#import <SAMobileCapture/SADefineOCR.h>
#import <SAMobileCapture/SADefineSimilarity.h>

@class SADate;

@interface SAReadDocumentParams : NSObject

@property (strong, nonatomic, readwrite) NSString *readDocumentNavBarTitle;
@property (nonatomic, assign) SACaptureQuality captureQaulity;
@property (nonatomic, assign) SAOCRAccuracyLevel ocrAccuracyLevel;
@property (nonatomic, assign) SASimilarityAlgorithm similarityAlgorithm;
@property (nonatomic, assign) double similarityThreshold;
@property (strong, nonatomic, readwrite) NSString *firstName;
@property (strong, nonatomic, readwrite) NSString *lastName;
@property (strong, nonatomic, readwrite) SADate *dateOfToday;
@property (nonatomic, assign) int maxDayCount;
@property (nonatomic, assign) int detectionWarningThreshold;
@property (nonatomic, assign) BOOL classifyBill;

@end
