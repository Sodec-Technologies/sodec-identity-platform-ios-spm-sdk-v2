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

#import <SAMobileCapture/SADefineButtonAction.h>
#import <SAMobileCapture/SADefineDetection.h>
#import <SAMobileCapture/SADefineIdentity.h>
#import <SAMobileCapture/SADefineKycVerificationResultDisplay.h>
#import <SAMobileCapture/SADefineProcessReturn.h>
#import <SAMobileCapture/SADefineVerificationResult.h>
#import <SAMobileCapture/SADefineVideo.h>
#import <SAMobileCapture/SAFlowCreator.h>

@class SACustomerVerification;
@class SAFlowConfig;
@class SAIdentityTypes;
@class SAVideoOutput;

NS_ASSUME_NONNULL_BEGIN

@protocol SACustomerVerificationDelegate <NSObject>

@required
- (void)customerVerificationDidCancel:(SACustomerVerification *)controller;
- (void)customerVerificationDidDone:(SACustomerVerification *)controller
          withVerificationResultType:(SAVerificationResultType)verificationResultType
              withButtonActionType:(SAButtonActionType)buttonActionType;
- (void)customerVerificationDidError:(SACustomerVerification *)controller
                    withErrorMessage:(NSString *)errorMessage;

@optional
/**
 * Görüntülü görüşme bu işlemde açık ama şu an kullanılamıyor (SIPMI-23). KYC başlamadan (Login/Start sonrası) ve End'den
 * hemen önce çağrılabilir; müşteri SDK içinde ayrıca bilgilendirilir.
 * @param reason SAVideoCallUnavailableReasonOutOfHours veya SAVideoCallUnavailableReasonNotReady
 * @param nextOpenAt OUT_OF_HOURS ise sonraki açılış anı; bilinmiyorsa nil
 */
- (void)customerVerification:(SACustomerVerification *)controller
    videoCallUnavailableWithReason:(NSString *)reason
                        nextOpenAt:(nullable NSDate *)nextOpenAt;

/**
 * Görüntülü görüşme bitti (SIPMI-27); customerVerificationDidDone'dan hemen önce çağrılır. Nihai karar görüşmede
 * verilir: yalnızca APPROVED onaydır, diğer sonuçlarda işlem kapanmıştır ve DidDone Rejected ile gelir.
 * @param result APPROVED / REJECTED / EXPIRED / DROPPED / ABANDONED (SAVideoCallStatus* sabitleri)
 * @param reasonCode Müşteriye gösterilebilir gerekçe kodu (VERIFICATION_FAILED, POOR_QUALITY, TECHNICAL_DISCONNECT,
 *        EXPIRED_QUEUE_TIMEOUT, EXPIRED_CALL_NOT_STARTED, OUT_OF_HOURS, VIDEO_CALL_NOT_JOINED, CUSTOMER_LEFT,
 *        VIDEO_CALL_CANCELLED); onayda ve gerekçesiz bitişte nil
 */
- (void)customerVerification:(SACustomerVerification *)controller
    videoCallDidFinishWithResult:(NSString *)result
                      reasonCode:(nullable NSString *)reasonCode;

@end

@interface SAApiManager : NSObject

// ---------------------------------------------------------------------------
// MARK: - Initialisation
// ---------------------------------------------------------------------------

- (instancetype)initWithBaseUrl:(NSString *)baseUrl
               withSubscriptionId:(NSString *)subscriptionId
              withSubscriptionKey:(NSString *)subscriptionKey;

- (instancetype)initWithBaseUrl:(NSString *)baseUrl
               withSubscriptionId:(NSString *)subscriptionId
              withSubscriptionKey:(NSString *)subscriptionKey
                      withTimeout:(NSTimeInterval)timeout;

// ---------------------------------------------------------------------------
// MARK: - SDK configuration properties
// ---------------------------------------------------------------------------

@property (nonatomic, strong, readonly)  NSString              *baseUrl;
@property (nonatomic, strong, readonly)  NSString              *subscriptionId;
@property (nonatomic, strong, readonly)  NSString              *subscriptionKey;
@property (nonatomic, assign, readwrite) NSTimeInterval         timeout;
@property (nonatomic, copy,   readwrite) NSString              *scenario;
@property (nonatomic, assign, readwrite) BOOL                   showServiceErrors;
@property (nonatomic, assign, readwrite) SAProcessReturnType    processReturnType;

// --- Görüntülü görüşme (SIPMI-25) ---
// Aydınlatma / rıza metni onayı host uygulamanın sorumluluğundadır ve SDK başlatılmadan önce alınır. İsteğe bağlı olarak
// onaylanan metnin sürümü ve onay anı verilirse görüşme talebine eklenir (backend denetim kaydına yazılır).
@property (nonatomic, copy,   nullable, readwrite) NSString    *videoCallConsentVersion;
@property (nonatomic, strong, nullable, readwrite) NSDate      *videoCallConsentAt;

// --- Identity & age ---
@property (nonatomic, assign, readwrite) NSInteger              minimumAgeForKyc;
@property (nonatomic, strong, readwrite) SAIdentityTypes       *undesiredIdentityTypes;

// --- Photocopy ---
@property (nonatomic, assign, readwrite) BOOL                   enableBWPhotoCopyDetection;
@property (nonatomic, assign, readwrite) CGFloat                originalThresholdForBWPhotoCopy;

// --- Hologram & OVI ---
@property (nonatomic, assign, readwrite) BOOL                   enableHologramAndOviDetection;
@property (nonatomic, assign, readwrite) SADetectionAccuracyLevel hologramDetectionAccuracyLevel;
@property (nonatomic, assign, readwrite) SADetectionAccuracyLevel oviDetectionAccuracyLevel;
@property (nonatomic, assign, readwrite) BOOL                   checkHologramAndOviOnNfcFail;
@property (nonatomic, assign, readwrite) BOOL                   skipHologramAndOviDetectionWhenFlashNotAvailable;
@property (nonatomic, assign, readwrite) BOOL                   evaluateAutomaticConfirmationWithoutSecurityItems;
@property (nonatomic, assign, readwrite) NSInteger              timeoutInSecondsForHologram;
@property (nonatomic, assign, readwrite) NSInteger              timeoutInSecondsForOvi;
@property (nonatomic, assign, readwrite) BOOL                   showTimeoutLabelForHologramAndOvi;

// --- NFC ---
@property (nonatomic, assign, readwrite) BOOL                   nfcVerificationMandatory;
@property (nonatomic, assign, readwrite) BOOL                   enableNfcVerificationForPassport;
@property (nonatomic, assign, readwrite) BOOL                   enableTimeoutIfNfcNotStarting;
@property (nonatomic, assign, readwrite) NSInteger              timeoutInSecondsForNfcStarting;
@property (nonatomic, assign, readwrite) BOOL                   showTimeoutLabelForNfc;
@property (nonatomic, assign, readwrite) NSInteger              countOfChipReaderExceptionToWarnUser;
@property (nonatomic, assign, readwrite) NSInteger              countOfChipReaderExceptionToSkipProcess;
@property (nonatomic, assign, readwrite) NSInteger              extraIncrementOfChipReaderExceptionInCaseOfFailure;
@property (nonatomic, assign, readwrite) BOOL                   skipActiveAuthenticationFailure;
@property (nonatomic, assign, readwrite) BOOL                   skipDocumentSignFailure;

// --- OCR / identity ---
@property (nonatomic, assign, readwrite) BOOL                   enableServerModelForIDCardVerification;
@property (nonatomic, assign, readwrite) BOOL                   useKPSService;
@property (nonatomic, assign, readwrite) BOOL                   useBirthDateForKpsApi;

// --- Liveness / selfie ---
@property (nonatomic, assign, readwrite) BOOL                   supportHeadTurningForActiveLivenessDetection;
@property (nonatomic, assign, readwrite) BOOL                   enableMaskDetection;
@property (nonatomic, assign, readwrite) BOOL                   checkMaskForEveryFace;
@property (nonatomic, assign, readwrite) NSInteger              maxCountOfAttemptsForLiveness;
@property (nonatomic, assign, readwrite) NSInteger              maxCountOfAttemptsForFaceVerification;
@property (nonatomic, assign, readwrite) CGFloat                similarityThresholdForComparison;
@property (nonatomic, assign, readwrite) CGFloat                occlusionThreshold;

// --- Screen record ---
@property (nonatomic, strong, readwrite) SAVideoOutput         *videoOutputOfScreenRecord;
@property (nonatomic, assign, readwrite) SAVideoQuality         videoQualityForScreenRecord;

// --- Address ---
@property (nonatomic, assign, readwrite) BOOL                   enableAddressProcess;
@property (nonatomic, assign, readwrite) BOOL                   checkOuterAndInnerFieldsInAddress;

// --- Result display ---
@property (nonatomic, assign, readwrite) SAKycVerificationResultDisplayType displayTypeOfKycVerificationResult;
@property (nonatomic, assign, readwrite) BOOL                   hideCompleteButtonWhenManualConfirmation;

// --- Signature & verification mode ---

/**
 * Controls whether the signature security item on the identity card is always checked,
 * or only when NFC chip reading was not performed.
 *
 * When @c YES, signature detection is enforced regardless of chip result.
 * When @c NO (default), it is only enforced when @c chipReaderResult is @c nil.
 */
@property (nonatomic, assign, readwrite) BOOL                   checkSignatureSecurityItem;

/**
 * Determines how a failed KYC result is reported to the host application.
 *
 * @c SAVerificationResultModePending (default): pending review state, Discover button visible.
 * @c SAVerificationResultModeReject: hard rejection with a specific message, Discover hidden.
 */
@property (nonatomic, assign, readwrite) SAVerificationResultMode verificationResultMode;

// ---------------------------------------------------------------------------
// MARK: - Flow configuration precedence
// ---------------------------------------------------------------------------

/**
 * Controls whether a dynamic @c steps node returned by @c api/Login/Start
 * overrides the client-provided @c SAFlowCreator (and @c SAApiManager
 * behavioral settings).
 *
 * @par When @c YES (default) — server is authoritative
 * The server response is the final authority. If @c api/Login/Start returns a
 * @c steps node, the server configuration is applied and any @c SAFlowCreator
 * passed by the client is ignored entirely. If the server returns a legacy
 * response (no @c steps node), the full legacy flow runs — again the client
 * @c SAFlowCreator is ignored. This is the recommended setting for production
 * because it allows server-side flow policy changes without a client release.
 *
 * @par When @c NO — client is authoritative
 * The SDK ignores the @c steps and @c global sections of the server response
 * entirely — even when they are present. Only session state (@c currentDate,
 * cookie, identity number) is still read from the server response.
 * - If an @c SAFlowCreator was supplied, that client-defined flow runs.
 * - If no @c SAFlowCreator was supplied, the full legacy flow runs.
 *
 * @warning Setting this to @c NO means server-driven policy changes (step
 * activation, security thresholds, timeouts, etc.) will have no effect on this
 * SDK instance. Use only when you need guaranteed client-controlled flows, such
 * as in automated tests or demo environments.
 *
 * Default: @c YES.
 *
 * @see SAFlowCreator
 */
@property (nonatomic, assign, readwrite) BOOL allowServerToOverrideFlow;

// ---------------------------------------------------------------------------
// MARK: - Factory
// ---------------------------------------------------------------------------

/**
 * Creates and configures an SACustomerVerification for the TC identity number flow (legacy).
 * Throws NSException if identityNumber is empty or the library is not loaded.
 */
- (SACustomerVerification *)createCustomerVerification:(id<SACustomerVerificationDelegate>)customerVerificationDelegate
                                    withIdentityNumber:(NSString *)identityNumber;

/**
 * Creates and configures an SACustomerVerification for the TC identity number flow with
 * an optional client-defined flow configuration.
 *
 * Validates @c flowCreator immediately and throws @c NSException if validation fails,
 * so that misconfiguration is caught at the call site rather than during a live KYC session.
 * Throws @c NSException if @c identityNumber is empty or the library is not loaded.
 *
 * @par Effective configuration rules — controlled by @c allowServerToOverrideFlow
 * - <b>Server authoritative</b> (@c allowServerToOverrideFlow @c = @c YES, default):
 *   @c flowCreator is <em>always ignored</em>. Server @c steps node wins; legacy server
 *   response falls back to the full legacy flow.
 * - <b>Client authoritative</b> (@c allowServerToOverrideFlow @c = @c NO):
 *   server @c steps and @c global are completely ignored. @c flowCreator wins;
 *   passing @c nil falls back to the full legacy flow.
 *
 * @param customerVerificationDelegate Delegate to receive completion, cancel, and error callbacks.
 * @param identityNumber Turkish national identity number (TC Kimlik No).
 * @param flowCreator Client-defined flow configuration, or @c nil to behave identically
 *   to @c createCustomerVerification:withIdentityNumber:.
 */
- (SACustomerVerification *)createCustomerVerification:(id<SACustomerVerificationDelegate>)customerVerificationDelegate
                                    withIdentityNumber:(NSString *)identityNumber
                                           flowCreator:(nullable SAFlowCreator *)flowCreator;

/**
 * Creates and configures an SACustomerVerification for the token-based dynamic flow.
 * Throws NSException if token is empty or the library is not loaded.
 */
- (SACustomerVerification *)createCustomerVerification:(id<SACustomerVerificationDelegate>)customerVerificationDelegate
                                             withToken:(NSString *)token;

/**
 * Creates and configures an SACustomerVerification for the token-based dynamic flow with
 * an optional client-defined flow configuration.
 *
 * Validates @c flowCreator immediately and throws @c NSException if validation fails,
 * so that misconfiguration is caught at the call site rather than during a live KYC session.
 * Throws @c NSException if @c token is empty or the library is not loaded.
 *
 * @par Effective configuration rules — controlled by @c allowServerToOverrideFlow
 * - <b>Server authoritative</b> (@c allowServerToOverrideFlow @c = @c YES, default):
 *   @c flowCreator is <em>always ignored</em>. Server @c steps node wins; legacy server
 *   response falls back to the full legacy flow.
 * - <b>Client authoritative</b> (@c allowServerToOverrideFlow @c = @c NO):
 *   server @c steps and @c global are completely ignored. @c flowCreator wins;
 *   passing @c nil falls back to the full legacy flow.
 *
 * @param customerVerificationDelegate Delegate to receive completion, cancel, and error callbacks.
 * @param token Session token obtained from the server for the token-based flow.
 * @param flowCreator Client-defined flow configuration, or @c nil to behave identically
 *   to @c createCustomerVerification:withToken:.
 */
- (SACustomerVerification *)createCustomerVerification:(id<SACustomerVerificationDelegate>)customerVerificationDelegate
                                             withToken:(NSString *)token
                                          flowCreator:(nullable SAFlowCreator *)flowCreator;

// ---------------------------------------------------------------------------
// MARK: - Dynamic flow helpers
// ---------------------------------------------------------------------------

/**
 * Applies non-nil/non-zero values from the api/Login/Start V3 response to SAApiManager properties.
 * Only behavioral properties are overridden; UI/branding settings remain under client control.
 * Android-only fields (readTimeoutMs, checkApplicationInDebugMode, etc.) are ignored on iOS.
 */
- (void)applyServiceConfig:(SAFlowConfig *)config;

/**
 * Maps a documentType/undesiredDocType JSON string to the corresponding SAIdentityType enum value.
 * Returns SAIdentityTypeDefault for nil or unknown strings.
 */
+ (SAIdentityType)identityTypeFromString:(nullable NSString *)value;

@end

NS_ASSUME_NONNULL_END
