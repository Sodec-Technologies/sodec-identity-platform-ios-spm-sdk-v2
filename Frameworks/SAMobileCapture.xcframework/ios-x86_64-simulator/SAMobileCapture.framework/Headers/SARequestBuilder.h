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

@class SARequestParams;
@class SAFaceParams;
@class SAVerificationResult;
@class SADocumentResult;

@interface SARequestBuilder : NSObject

+ (void)callIDDetectionApi:(NSTimeInterval)timeout imageData:(NSData * _Nonnull)imageData success:(void(^_Nonnull)(SADocumentResult * _Nonnull documentResult, UIImage * _Nullable documentImage))sucessCallback failure:(void(^_Nonnull)(NSString * _Nonnull errorCode, NSString * _Nonnull errorMessage))failureCallback;

+ (void)callFaceDetectionApi:(SARequestParams * _Nonnull)requestParams timeout:(NSTimeInterval)timeout faceParams:(SAFaceParams * _Nonnull)faceParams imageData:(NSData * _Nonnull)imageData success:(void(^_Nonnull)(NSString * _Nonnull faceId))sucessCallback failure:(void(^_Nonnull)(NSString * _Nonnull errorCode, NSString * _Nonnull errorMessage))failureCallback;

+ (void)callFaceVerificationApi:(SARequestParams * _Nonnull)requestParams timeout:(NSTimeInterval)timeout faceId1:(NSString * _Nonnull)faceId1 faceId2:(NSString * _Nonnull)faceId2 success:(void(^_Nonnull)(SAVerificationResult * _Nonnull verificationResult))sucessCallback failure:(void(^_Nonnull)(NSString * _Nonnull errorCode, NSString * _Nonnull errorMessage))failureCallback;

+ (void)callFaceMatchingApi:(SARequestParams * _Nonnull)requestParams timeout:(NSTimeInterval)timeout faceParams:(SAFaceParams * _Nonnull)faceParams sourceImageData:(NSData * _Nonnull)sourceImageData targetImageData:(NSData * _Nonnull)targetImageData success:(void(^_Nonnull)(SAVerificationResult * _Nonnull verificationResult))sucessCallback failure:(void(^_Nonnull)(NSString * _Nonnull errorCode, NSString * _Nonnull errorMessage))failureCallback;

@end
