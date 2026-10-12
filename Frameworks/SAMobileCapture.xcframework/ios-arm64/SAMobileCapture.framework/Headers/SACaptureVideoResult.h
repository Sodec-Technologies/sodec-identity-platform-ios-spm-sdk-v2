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

@interface SACaptureVideoResult : NSObject

@property (nonatomic, assign) BOOL available;
@property (strong, nonatomic, readwrite) NSString *videoPath;
@property (strong, nonatomic, readwrite) NSString *videoFileType;
@property (strong, nonatomic, readwrite) NSString *videoMimeType;
@property (strong, nonatomic, readwrite) NSString *audioPath;
@property (strong, nonatomic, readwrite) NSString *audioFileType;
@property (strong, nonatomic, readwrite) NSString *audioMimeType;
@property (nonatomic, assign) int audioSampleRate;

@end
