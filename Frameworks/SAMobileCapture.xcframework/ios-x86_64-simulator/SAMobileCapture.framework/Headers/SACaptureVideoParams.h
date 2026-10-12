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

#import <SAMobileCapture/SADefineAudio.h>
#import <SAMobileCapture/SADefineVideo.h>

@class SATTSParams;

@interface SACaptureVideoParams : NSObject

@property (nonatomic, assign) BOOL enabled;
@property (strong, nonatomic, readwrite) NSString *videoNavBarTitle;
@property (strong, nonatomic, readwrite) NSString *folderNameForVideo;
@property (strong, nonatomic, readwrite) NSString *desiredSentence;
@property (strong, nonatomic, readwrite) NSString *recordButtonDescription;
@property (strong, nonatomic, readwrite) SATTSParams *ttsParams;
@property (nonatomic, assign) SAAudioFormat audioFormat;
@property (nonatomic, assign) SAVideoQuality videoQuality;
@property (nonatomic, assign) BOOL faceDetectionInVideo;

@end
