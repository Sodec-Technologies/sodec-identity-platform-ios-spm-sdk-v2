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

#import <SAMobileCapture/SADefineVideo.h>
#import <SAMobileCapture/SADefineCapture.h>
#import <SAMobileCapture/SADefineFace.h>

#define SA_SELFIE_PAGE_FILE_NAME @"sa_selfie"

@class SACaptureSelfie;
@class SACaptureVideoParams;
@class SACaptureVideoResult;
@class SAFaceRecognition;
@class SASpeechRecognition;
@class SACaptcha;
@class SAVideoOutput;
@class SAApiManager;

@protocol SACaptureSelfieDelegate <NSObject>

@required
- (void)captureSelfieDidCancel:(SACaptureSelfie *)controller;
- (void)captureSelfieDidDone:(SACaptureSelfie *)controller withScreenRecordPath:(NSString *)screenRecordPath withScreenRecordFileType:(NSString *)screenRecordFileType withScreenRecordMimeType:(NSString *)screenRecordMimeType withSelfiePath:(NSString *)selfiePath withFacePath:(NSString *)facePath withIsEncrypted:(BOOL)isEncrypted withCaptureVideoResult:(SACaptureVideoResult *)videoCaptureResult;
- (void)captureSelfieOnFaceRecognition:(NSString *)screenRecordPath withScreenRecordFileType:(NSString *)screenRecordFileType withScreenRecordMimeType:(NSString *)screenRecordMimeType withSelfieData:(NSData *)selfieData withFaceData:(NSData *)faceData withFaceRecognition:(SAFaceRecognition *)faceRecognition;
@optional
- (void)captureSelfieOnSpeechRecognition:(NSString *)videoPath withVideoFileType:(NSString *)videoFileType withVideoMimeType:(NSString *)videoMimeType withAudioPath:(NSString *)audioPath withAudioFileType:(NSString *)audioFileType withAudioMimeType:(NSString *)audioMimeType withAudioSampleRate:(int)audioSampleRate withSpeechRecognition:(SASpeechRecognition *)speechRecognition;

@end

@interface SACaptureSelfie : UIViewController
{
    id<SACaptureSelfieDelegate> __unsafe_unretained delegate;
}

@property (unsafe_unretained) id<SACaptureSelfieDelegate> delegate;
@property (strong, nonatomic, readwrite) NSString *selfieNavBarTitle;
@property (strong, nonatomic, readwrite) NSString *folderNameForSelfie;
@property (nonatomic, assign) SAVideoQuality screenRecordQuality;
@property (nonatomic, assign) SACaptureQuality captureQuality;
@property (nonatomic, assign) SAFaceMode faceMode;
@property (nonatomic, assign) BOOL showScreenRecordActiveIcon;
@property (nonatomic, assign) BOOL showScreenRecordMuteIcon;
@property (nonatomic, assign) BOOL encryptFile;
@property (strong, nonatomic, readwrite) SACaptureVideoParams *captureVideoParams;
@property (strong, nonatomic, readwrite) SACaptcha *captcha;
@property (strong, nonatomic, readwrite) SAVideoOutput *videoOutput;
@property (strong, nonatomic, readwrite) SAApiManager *apiManager;
@property (nonatomic, assign) BOOL checkMaskForEveryFace;
@property (strong, nonatomic, readwrite) NSString *maskDetectionModelFilePath;
@property (nonatomic, assign) int maxCountOfAttemptsForLiveness;
@property (nonatomic, assign) int maxCountOfAttemptsForFaceRecognition;
@property (nonatomic, assign, readwrite) BOOL supportHeadTurningForActiveLivenessDetection;
@property (strong, nonatomic, readwrite) NSString *facePathForIdentityFace;

@end
