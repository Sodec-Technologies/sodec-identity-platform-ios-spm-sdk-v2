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
@class SAFlowConfig;

NS_ASSUME_NONNULL_BEGIN

// ---------------------------------------------------------------------------
// MARK: - Document type constants
// ---------------------------------------------------------------------------

/**
 * Turkish new-generation identity card (Kimlik Kartı).
 *
 * Use as the @c nfcDocumentType value when the document to be NFC-read is a
 * TR new-generation ID card. This is the most common value for domestic KYC flows.
 */
extern NSString * const SAFlowCreatorDocumentTypeNewIdentityCard;

/**
 * Turkish biometric passport (Pasaport).
 *
 * Use as the @c nfcDocumentType value when the document to be NFC-read is a
 * TR biometric passport.
 */
extern NSString * const SAFlowCreatorDocumentTypePassport;

// ---------------------------------------------------------------------------
// MARK: - SAFlowCreator
// ---------------------------------------------------------------------------

/**
 * Client-defined KYC flow configuration passed to
 * @c -[SAApiManager createCustomerVerification:withIdentityNumber:flowCreator:]
 * or
 * @c -[SAApiManager createCustomerVerification:withToken:flowCreator:].
 *
 * @par Purpose
 * Allows the developer to define which KYC steps should run and supply
 * step-specific access keys at the code level, without relying solely on the
 * server's @c api/Login/Start response. This is useful for flows where the
 * step configuration must be guaranteed by the client (e.g., automated tests,
 * environments where server-side policy cannot be changed in time).
 *
 * @par Effective configuration rules
 * The @c allowServerToOverrideFlow property of @c SAApiManager controls which
 * source is authoritative:
 *
 * - <b>Server authoritative</b> (@c SAApiManager.allowServerToOverrideFlow @c = @c YES,
 *   default): this object is <em>always ignored</em>. If the server returns a
 *   @c steps node the server configuration is applied; if the server returns a
 *   legacy response (no @c steps node) the full legacy flow runs. Either way
 *   this @c SAFlowCreator has no effect.
 *
 * - <b>Client authoritative</b> (@c SAApiManager.allowServerToOverrideFlow @c = @c NO):
 *   the server @c steps and @c global sections are completely ignored — even
 *   when they are present. Only session state (@c currentDate, cookie, identity
 *   number) is still read from the server. If this object is non-@c nil the
 *   client-defined flow runs; if it is @c nil the full legacy flow runs.
 *
 * @par Step order is always fixed
 * @c captureDocument → @c nfc → @c liveness → @c address.
 * Enabling a subset does not change the relative order of the remaining steps.
 *
 * @par Usage example — NFC + Selfie, no OCR
 * @code
 * SAFlowCreator *creator = [[SAFlowCreator alloc] init];
 * creator.nfc              = YES;
 * creator.nfcSerialNo      = @"A12345678";
 * creator.nfcDocumentType  = SAFlowCreatorDocumentTypeNewIdentityCard;
 * creator.nfcDateOfExpiry  = [[SADate alloc] initWithYear:2029 month:3 day:30];
 * creator.nfcDateOfBirth   = [[SADate alloc] initWithYear:1997 month:3 day:30];
 * creator.liveness         = YES;
 *
 * NSError *validationError;
 * if (![creator validateWithError:&validationError])
 * {
 *     NSLog(@"Invalid flow config: %@", validationError.localizedDescription);
 *     return;
 * }
 *
 * SACustomerVerification *vc = [self.apiManager
 *     createCustomerVerification:self
 *     withToken:token
 *     flowCreator:creator];
 * [self presentViewController:vc animated:YES completion:nil];
 * @endcode
 *
 * Call @c validateWithError: before passing the object to
 * @c createCustomerVerification:withToken:flowCreator:. The factory method also
 * validates internally and throws @c NSException on failure so that
 * misconfiguration is caught at the call site rather than during a live KYC
 * session.
 */
@interface SAFlowCreator : NSObject

// ---------------------------------------------------------------------------
// MARK: - Step enable flags
// ---------------------------------------------------------------------------

/**
 * Enables or disables the OCR (document capture) step.
 *
 * When @c YES, the NFC reader and liveness step will automatically receive the
 * access keys and face IDs extracted from the scanned document. Properties
 * @c nfcSerialNo, @c nfcDocumentType, @c nfcDateOfExpiry, and @c nfcDateOfBirth
 * are ignored when @c captureDocument @c = @c YES.
 *
 * Default: @c NO.
 */
@property (nonatomic, assign, readwrite) BOOL captureDocument;

/**
 * Enables or disables the NFC chip-reading step.
 *
 * @par Required companion properties when @c YES and @c captureDocument @c = @c NO
 * @c nfcSerialNo, @c nfcDocumentType, @c nfcDateOfExpiry, and @c nfcDateOfBirth
 * are all required. @c validateWithError: enforces these constraints and returns
 * an error if any of them is missing or invalid.
 *
 * When @c captureDocument @c = @c YES the NFC reader derives all access keys
 * from the OCR result automatically and the above four properties are ignored.
 *
 * Default: @c NO.
 */
@property (nonatomic, assign, readwrite) BOOL nfc;

/**
 * Enables or disables the liveness detection (selfie) step.
 *
 * @par Required companion property for selfie-only flows
 * When @c liveness @c = @c YES, @c captureDocument @c = @c NO, and
 * @c nfc @c = @c NO, the @c livenessReferenceFaceId is required. @c validateWithError:
 * returns an error if it is missing.
 *
 * When OCR or NFC precedes the selfie step the reference face is resolved
 * automatically from those results and @c livenessReferenceFaceId is ignored.
 *
 * Default: @c NO.
 */
@property (nonatomic, assign, readwrite) BOOL liveness;

/**
 * Enables or disables the address verification step.
 *
 * Address-only flow (@c address @c = @c YES with all other steps @c NO) is
 * not supported and @c validateWithError: will return an error.
 *
 * Default: @c NO.
 */
@property (nonatomic, assign, readwrite) BOOL address;

// ---------------------------------------------------------------------------
// MARK: - NFC access keys
// ---------------------------------------------------------------------------

/**
 * Document serial number used to derive the NFC chip access key (BAC/PACE).
 *
 * @par When required
 * @c nfc @c = @c YES and @c captureDocument @c = @c NO. If OCR runs before NFC,
 * the serial number is extracted from the scanned document automatically and
 * this value is not used even if it is set.
 *
 * @par When ignored
 * @c captureDocument @c = @c YES — serial number is read from the OCR result.
 *
 * Example: @c @"A12345678"
 */
@property (nonatomic, copy, nullable) NSString *nfcSerialNo;

/**
 * Document type supplied to the NFC reader and used by @c SAKyc to determine
 * identity type.
 *
 * @par When required
 * @c nfc @c = @c YES and @c captureDocument @c = @c NO. Must be exactly
 * @c SAFlowCreatorDocumentTypeNewIdentityCard or @c SAFlowCreatorDocumentTypePassport.
 * Any other string is rejected by @c validateWithError:. Only Turkish
 * new-generation ID card and passport are supported by the NFC reader.
 *
 * @par When ignored
 * @c captureDocument @c = @c YES — the document type is derived from the OCR result.
 */
@property (nonatomic, copy, nullable) NSString *nfcDocumentType;

/**
 * Document expiry date used to derive the NFC chip access key (BAC/PACE).
 *
 * @par When required
 * @c nfc @c = @c YES and @c captureDocument @c = @c NO.
 *
 * @par When ignored
 * @c captureDocument @c = @c YES — the expiry date is read from the document.
 */
@property (nonatomic, strong, nullable) SADate *nfcDateOfExpiry;

/**
 * Date of birth used to derive the NFC chip access key (BAC/PACE).
 *
 * @par When required
 * @c nfc @c = @c YES and @c captureDocument @c = @c NO.
 *
 * @par When ignored
 * @c captureDocument @c = @c YES — the date of birth is read from the document.
 */
@property (nonatomic, strong, nullable) SADate *nfcDateOfBirth;

/**
 * Pre-existing face ID used as the reference in the NFC @c face/verify call.
 *
 * @par Always optional
 * When present, the chip face extracted from the NFC chip is compared against
 * this face ID to produce @c chipVerificationResult in @c SAKycResult.
 *
 * @par Override behaviour
 * If @c captureDocument @c = @c YES, the @c identityFaceId produced by OCR
 * takes priority over this field regardless of its value.
 * Priority: OCR @c identityFaceId > this field > skip.
 *
 * When neither source provides a reference face, @c face/verify is skipped for
 * the NFC step and @c chipFaceId is forwarded to the selfie step (if active).
 */
@property (nonatomic, copy, nullable) NSString *nfcFaceId;

// ---------------------------------------------------------------------------
// MARK: - Liveness access key
// ---------------------------------------------------------------------------

/**
 * Pre-existing face ID used as the reference for the selfie @c face/verify call.
 *
 * @par When required
 * @c liveness @c = @c YES, @c captureDocument @c = @c NO, and
 * @c nfc @c = @c NO (selfie-only flow). In all other step combinations the
 * reference face is resolved automatically:
 * - OCR + NFC + Selfie / NFC + Selfie → @c chipFaceId from the NFC step
 * - OCR + Selfie → @c identityFaceId from the OCR step
 *
 * @par Priority
 * @c chipFaceId > @c identityFaceId > this field.
 * Even if set, this value is used only when neither NFC nor OCR has produced
 * a face ID in the current session.
 */
@property (nonatomic, copy, nullable) NSString *livenessReferenceFaceId;

// ---------------------------------------------------------------------------
// MARK: - Internal conversion (SDK use only)
// ---------------------------------------------------------------------------

/**
 * Converts this client flow configuration into a synthetic @c SAFlowConfig that the
 * SDK processes through the same pipeline as a server-driven configuration.
 *
 * @par For SDK internal use only
 * This method is called by @c SACustomerVerification after the server response has been
 * received and session state has been extracted. Do not call this method directly.
 *
 * Only step enable flags, NFC access keys, @c nfcFaceId, and
 * @c livenessReferenceFaceId are populated. Behavioral parameters (timeouts,
 * exception thresholds, etc.) are intentionally omitted so that the values
 * already configured on @c SAApiManager remain in effect.
 * @c applyServiceConfig: is @em not called for synthetic configs.
 *
 * @return A populated @c SAFlowConfig with @c flattenSteps already called.
 */
- (SAFlowConfig *)toFlowConfig;

// ---------------------------------------------------------------------------
// MARK: - Validation
// ---------------------------------------------------------------------------

/**
 * Validates the configuration and writes a detailed error if any required
 * field is missing or the step combination is invalid.
 *
 * Call this method before passing the object to
 * @c createCustomerVerification:withToken:flowCreator: so that configuration
 * errors surface immediately rather than during a live KYC session.
 *
 * @par Validation rules
 * - At least one step must be enabled.
 * - Address-only flow (@c address @c = @c YES with all other steps @c NO) is
 *   not supported.
 * - When @c nfc @c = @c YES and @c captureDocument @c = @c NO:
 *   @c nfcSerialNo, @c nfcDocumentType, @c nfcDateOfExpiry, and
 *   @c nfcDateOfBirth are all required.
 * - @c nfcDocumentType must be @c SAFlowCreatorDocumentTypeNewIdentityCard or
 *   @c SAFlowCreatorDocumentTypePassport.
 * - When @c liveness @c = @c YES, @c captureDocument @c = @c NO, and
 *   @c nfc @c = @c NO: @c livenessReferenceFaceId is required.
 *
 * @param error On failure, populated with an @c NSError in the
 *   @c SAFlowCreatorErrorDomain domain describing the first validation
 *   violation. Pass @c NULL if error details are not needed.
 * @return @c YES if the configuration is valid; @c NO otherwise.
 */
- (BOOL)validateWithError:(NSError **)error;

@end

NS_ASSUME_NONNULL_END
