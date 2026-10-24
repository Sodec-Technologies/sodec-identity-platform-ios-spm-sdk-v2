/*
 * Copyright (C) 2026 Sodec Apps Bilisim Teknolojileri, Inc. - All rights reserved.
 *
 * This source code and all associated files are the confidential and proprietary property
 * of Sodec Apps Bilisim Teknolojileri, Inc. Unauthorized copying, distribution, or disclosure
 * of this file, via any medium, is strictly prohibited.
 *
 * This software is protected under international copyright and intellectual property laws.
 * Use of this software is subject to the terms of a valid license agreement with
 * Sodec Apps Bilisim Teknolojileri, Inc.
 *
 * Proprietary and confidential.
 * Written by Hasan Dertli <hasan.dertli@sodec.com>
 *
 * Sodec Apps Bilisim Teknolojileri, Inc.
 * https://sodec.com
 * support@sodec.com
 */

#import <Foundation/Foundation.h>

@class SADate;

NS_ASSUME_NONNULL_BEGIN

// ---------------------------------------------------------------------------
// documentType string constants — "passport" | "newIdentityCard"
// ---------------------------------------------------------------------------
extern NSString * const SAFlowConfigDocumentTypePassport;
extern NSString * const SAFlowConfigDocumentTypeNewIdentityCard;

// ---------------------------------------------------------------------------
// undesiredDocTypes string constants — mirrors SAIdentityType enum names
// ---------------------------------------------------------------------------
extern NSString * const SAFlowConfigDocumentTypeOldIdentityCard;
extern NSString * const SAFlowConfigDocumentTypeOldDrivingLicense;
extern NSString * const SAFlowConfigDocumentTypeNewDrivingLicense;
extern NSString * const SAFlowConfigDocumentTypeOldResidencePermit;
extern NSString * const SAFlowConfigDocumentTypeNewResidencePermit;
extern NSString * const SAFlowConfigDocumentTypeTemporaryProtection;

// ---------------------------------------------------------------------------
// SAFlowConfigGlobal
// ---------------------------------------------------------------------------
@interface SAFlowConfigGlobal : NSObject

@property (nonatomic, assign)            NSInteger  minAge;
@property (nonatomic, assign)            CGFloat    similarityThreshold;
@property (nonatomic, nullable, strong)  NSNumber  *enableHologramAndOviDetection;
@property (nonatomic, nullable, copy)    NSString  *hologramAccuracy;
@property (nonatomic, nullable, copy)    NSString  *oviAccuracy;
@property (nonatomic, assign)            NSInteger  hologramTimeoutSeconds;
@property (nonatomic, assign)            NSInteger  oviTimeoutSeconds;
@property (nonatomic, nullable, strong)  NSNumber  *skipOviWhenNoFlash;
@property (nonatomic, nullable, strong)  NSNumber  *checkOviOnNfcFail;
@property (nonatomic, assign)            CGFloat    identityFaceMaskThreshold;
@property (nonatomic, nullable, strong)  NSNumber  *autoConfirmWithoutSecurityItems;

+ (nullable SAFlowConfigGlobal *)fromDictionary:(nullable NSDictionary *)dict;

@end

// ---------------------------------------------------------------------------
// SAFlowConfigStepCaptureDocument
// ---------------------------------------------------------------------------
@interface SAFlowConfigStepCaptureDocument : NSObject

@property (nonatomic, assign)            BOOL                   enable;
@property (nonatomic, nullable, strong)  NSNumber              *enableNvi;
@property (nonatomic, nullable, strong)  NSNumber              *useNviBirthDate;
@property (nonatomic, nullable, copy)    NSArray<NSString *>   *undesiredDocTypes;
@property (nonatomic, nullable, strong)  NSNumber              *enablePhotocopyDetection;
@property (nonatomic, assign)            CGFloat                photocopyThreshold;
@property (nonatomic, nullable, strong)  NSNumber              *enableServerModel;

+ (nullable SAFlowConfigStepCaptureDocument *)fromDictionary:(nullable NSDictionary *)dict;

@end

// ---------------------------------------------------------------------------
// SAFlowConfigStepNfc
// ---------------------------------------------------------------------------
@interface SAFlowConfigStepNfc : NSObject

@property (nonatomic, assign)            BOOL      enable;
@property (nonatomic, nullable, copy)    NSString *serialNo;
@property (nonatomic, nullable, copy)    NSString *documentType;
@property (nonatomic, nullable, strong)  SADate   *dateOfBirth;
@property (nonatomic, nullable, strong)  SADate   *dateOfExpiry;
@property (nonatomic, nullable, copy)    NSString *faceId;
@property (nonatomic, nullable, strong)  NSNumber *mandatory;
@property (nonatomic, nullable, strong)  NSNumber *enableForPassport;
@property (nonatomic, nullable, strong)  NSNumber *enableStartTimeout;
@property (nonatomic, assign)            NSInteger startTimeoutSeconds;
@property (nonatomic, assign)            NSInteger warnAfterExceptions;
@property (nonatomic, assign)            NSInteger skipAfterExceptions;
@property (nonatomic, assign)            NSInteger exceptionIncrement;
@property (nonatomic, nullable, strong)  NSNumber *skipSignFailure;
@property (nonatomic, nullable, strong)  NSNumber *skipActiveAuthFailure;

+ (nullable SAFlowConfigStepNfc *)fromDictionary:(nullable NSDictionary *)dict;

@end

// ---------------------------------------------------------------------------
// SAFlowConfigStepLiveness
// ---------------------------------------------------------------------------
@interface SAFlowConfigStepLiveness : NSObject

@property (nonatomic, assign)            BOOL      enable;
@property (nonatomic, nullable, copy)    NSString *referenceFaceId;
@property (nonatomic, nullable, strong)  NSNumber *supportHeadTurning;
@property (nonatomic, nullable, strong)  NSNumber *enableMaskDetection;
@property (nonatomic, nullable, strong)  NSNumber *checkMaskForEveryFace;
@property (nonatomic, assign)            NSInteger maxAttempts;
@property (nonatomic, assign)            NSInteger maxFaceVerifyAttempts;

+ (nullable SAFlowConfigStepLiveness *)fromDictionary:(nullable NSDictionary *)dict;

@end

// ---------------------------------------------------------------------------
// SAFlowConfigStepAddress
// ---------------------------------------------------------------------------
@interface SAFlowConfigStepAddress : NSObject

@property (nonatomic, assign)            BOOL      enable;
@property (nonatomic, nullable, strong)  NSNumber *checkOuterAndInnerFields;

+ (nullable SAFlowConfigStepAddress *)fromDictionary:(nullable NSDictionary *)dict;

@end

// ---------------------------------------------------------------------------
// SAFlowConfigVideoCall — "videoCall" block of api/Login/Start and the data of
// GET api/video-call/availability (SIPMI-23; sözleşme docs/video-call-sdk-api.md §3.1-3.2)
// ---------------------------------------------------------------------------
extern NSString * const SAVideoCallUnavailableReasonNotEnabled;   // "NOT_ENABLED"
extern NSString * const SAVideoCallUnavailableReasonOutOfHours;   // "OUT_OF_HOURS"
extern NSString * const SAVideoCallUnavailableReasonNotReady;     // "NOT_READY"

@interface SAFlowConfigVideoCall : NSObject

/// Bu işlemde görüntülü görüşme var mı (müşteri lisansı + müşteri/akış adımı).
@property (nonatomic, assign)            BOOL      enabled;
/// Şu an kuyruğa girilebilir mi (hizmet hazır ve çalışma saati içinde).
@property (nonatomic, assign)            BOOL      available;
/// available = NO ise: NOT_ENABLED / OUT_OF_HOURS / NOT_READY.
@property (nonatomic, nullable, copy)    NSString *unavailableReason;
/// OUT_OF_HOURS ise sonraki açılış anı; bilinmiyorsa nil.
@property (nonatomic, nullable, strong)  NSDate   *nextOpenAt;
/// Kuyruk bekleme üst sınırı (sn); bilinmiyorsa 0.
@property (nonatomic, assign)            NSInteger maxQueueWaitSeconds;
/// available = YES ise kaba bekleme tahmini (sn); bilinmiyorsa nil.
@property (nonatomic, nullable, strong)  NSNumber *estimatedWaitSeconds;
/// Yalnızca availability ucunda: kuyrukta bekleyen müşteri sayısı.
@property (nonatomic, nullable, strong)  NSNumber *queuedCount;

/// Görüşme açık ama şu an kullanılamıyor (müşteri bilgilendirilmeli).
@property (nonatomic, readonly)          BOOL      isEnabledButUnavailable;

+ (nullable SAFlowConfigVideoCall *)fromDictionary:(nullable NSDictionary *)dict;

@end

// ---------------------------------------------------------------------------
// SAFlowConfigSteps — wrapper for the "steps" JSON object
// ---------------------------------------------------------------------------
@interface SAFlowConfigSteps : NSObject

@property (nonatomic, nullable, strong) SAFlowConfigStepCaptureDocument *captureDocument;
@property (nonatomic, nullable, strong) SAFlowConfigStepNfc              *nfc;
@property (nonatomic, nullable, strong) SAFlowConfigStepLiveness         *livenessDetection;
@property (nonatomic, nullable, strong) SAFlowConfigStepAddress          *address;

+ (nullable SAFlowConfigSteps *)fromDictionary:(nullable NSDictionary *)dict;

@end

// ---------------------------------------------------------------------------
// SAFlowConfig — top-level api/Login/Start V3 response model
// ---------------------------------------------------------------------------
@interface SAFlowConfig : NSObject

@property (nonatomic, nullable, strong) SADate   *currentDate;
@property (nonatomic, nullable, copy)   NSString *identityNumber;
@property (nonatomic, nullable, copy)   NSString *cookieOfSession;
@property (nonatomic, nullable, copy)   NSString *error;

@property (nonatomic, nullable, strong) SAFlowConfigGlobal *global;
@property (nonatomic, nullable, strong) SAFlowConfigSteps  *steps;

/// Görüntülü görüşme ön kontrol bilgisi; sunucu göndermediyse (eski backend) nil = görüşme yok.
@property (nonatomic, nullable, strong) SAFlowConfigVideoCall *videoCall;

// Convenience accessors (populated by flattenSteps)
@property (nonatomic, nullable, strong) SAFlowConfigStepCaptureDocument *captureDocument;
@property (nonatomic, nullable, strong) SAFlowConfigStepNfc              *nfc;
@property (nonatomic, nullable, strong) SAFlowConfigStepLiveness         *livenessDetection;
@property (nonatomic, nullable, strong) SAFlowConfigStepAddress          *address;

/**
 * Parses the api/Login/Start V3 JSON response dictionary into an SAFlowConfig.
 * The cookie is extracted from the HTTP response headers separately and injected afterward.
 */
+ (SAFlowConfig *)fromDictionary:(NSDictionary *)dict;

/**
 * Promotes nested step references to top-level convenience properties.
 * Must be called once after fromDictionary:.
 */
- (void)flattenSteps;

/**
 * Validates mandatory fields per the dynamic KYC requirements (DYNAMIC_KYC_REQUIREMENTS.md §10).
 * Checks include:
 *   - Invalid step combinations (no active steps; address-only)
 *   - NFC without OCR: serialNo, dateOfBirth, dateOfExpiry, documentType required
 *   - Selfie without OCR and NFC: referenceFaceId required
 * Returns nil if validation passes, or an NSError describing the first violation.
 */
- (nullable NSError *)validate;

@end

NS_ASSUME_NONNULL_END
