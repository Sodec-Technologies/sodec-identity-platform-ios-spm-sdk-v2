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

@class SACaptureVideo;
@class SACaptureVideoParams;
@class SACaptureVideoResult;
@class SASpeechRecognition;

@protocol SACaptureVideoDelegate <NSObject>

@required
- (void)captureVideoDidCancel:(SACaptureVideo *)controller;
- (void)captureVideoDidDone:(SACaptureVideo *)controller withCaptureVideoResult:(SACaptureVideoResult *)captureVideoResult;
- (void)captureVideoOnSpeechRecognition:(NSString *)videoPath withVideoFileType:(NSString *)videoFileType withVideoMimeType:(NSString *)videoMimeType withAudioPath:(NSString *)audioPath withAudioFileType:(NSString *)audioFileType withAudioMimeType:(NSString *)audioMimeType withAudioSampleRate:(int)audioSampleRate withSpeechRecognition:(SASpeechRecognition *)speechRecognition;

@end

@interface SACaptureVideo : UIViewController
{
    id<SACaptureVideoDelegate> __unsafe_unretained delegate;
}

@property (unsafe_unretained) id<SACaptureVideoDelegate> delegate;
@property (strong, nonatomic, readwrite) SACaptureVideoParams *captureVideoParams;

@end
