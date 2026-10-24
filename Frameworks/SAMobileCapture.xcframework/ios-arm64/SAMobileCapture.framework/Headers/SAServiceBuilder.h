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

@class SAAddress;
@class SAChipReaderResult;
@class SACustomerData;
@class SADate;
@class SAFlowConfig;
@class SAFlowConfigVideoCall;
@class SAVideoCallStatus;
@class SAFormDataList;
@class SAIdentityData;
@class SAKycResult;
@class SARequestParams;
@class SASecurityItems;
@class SAVerificationResult;

NS_ASSUME_NONNULL_BEGIN

@interface SAServiceBuilder : NSObject

+ (void)getAddressService:(SARequestParams *)requestParams
                  timeout:(NSTimeInterval)timeout
                  success:(void (^)(NSArray *addressItems))successCallback
                  failure:(void (^)(NSString *errorCode, NSString *errorMessage))failureCallback;

+ (void)getModelService:(SARequestParams *)requestParams
                timeout:(NSTimeInterval)timeout
   directoryNameOfModel:(NSString *)directoryNameOfModel
      fileNameOfModel:(NSString *)fileNameOfModel
  fileExtensionOfModel:(NSString *)fileExtensionOfModel
          nameOfModel:(NSString *)nameOfModel
               success:(void (^)(NSString *modelPath))successCallback
               failure:(void (^)(NSString *errorCode, NSString *errorMessage))failureCallback;

+ (void)startProcessService:(SARequestParams *)requestParams
                    timeout:(NSTimeInterval)timeout
                   scenario:(NSString *)scenario
                    success:(void (^)(SADate *currentDate, NSString *cookieOfSession))successCallback
                    failure:(void (^)(NSString *errorCode, NSString *errorMessage))failureCallback;

+ (void)startProcessServiceV2:(SARequestParams *)requestParams
                       timeout:(NSTimeInterval)timeout
                         token:(NSString *)token
                      scenario:(NSString *)scenario
                       success:(void (^)(SADate *currentDate, NSString *idNumber, NSString *cookieOfSession))successCallback
                       failure:(void (^)(NSString *errorCode, NSString *errorMessage))failureCallback;

/**
 * V3: Calls api/Login/Start with a token and returns the full SAFlowConfig model.
 * Automatically checks the "error" field in the response and runs validate on the parsed config.
 * If either check fails, failureCallback is called with an error code and message.
 */
+ (void)startProcessServiceV3:(SARequestParams *)requestParams
                        timeout:(NSTimeInterval)timeout
                          token:(NSString *)token
                       scenario:(NSString *)scenario
                        success:(void (^)(SAFlowConfig *config))successCallback
                        failure:(void (^)(NSString *errorCode, NSString *errorMessage))failureCallback;

/**
 * Calls api/Login/Start with an identity number (IDNumber flow) and parses the response as
 * SAFlowConfig — identical to startProcessServiceV3 but sends the identity number via the
 * "user-id-number" header instead of a Token body field.
 * If the server returns no "steps" node, SAActiveSteps will resolve to nil and the legacy
 * full flow will be used automatically (backward-compatible behaviour).
 */
+ (void)startProcessServiceV3ForIDNumber:(SARequestParams *)requestParams
                                  timeout:(NSTimeInterval)timeout
                           identityNumber:(NSString *)identityNumber
                                 scenario:(NSString *)scenario
                                  success:(void (^)(SAFlowConfig *config))successCallback
                                  failure:(void (^)(NSString *errorCode, NSString *errorMessage))failureCallback;

+ (void)getCustomerDataService:(SARequestParams *)requestParams
                        timeout:(NSTimeInterval)timeout
               cookieOfSession:(NSString *)cookieOfSession
                identityNumber:(NSString *)identityNumber
            useBirthDateForKpsApi:(BOOL)useBirthDateForKpsApi
                   dateOfBirth:(nullable NSString *)dateOfBirth
                        success:(void (^)(SACustomerData *customerData))successCallback
                        failure:(void (^)(NSString *errorCode, NSString *errorMessage))failureCallback;

+ (void)uploadFilesService:(SARequestParams *)requestParams
                   timeout:(NSTimeInterval)timeout
           cookieOfSession:(NSString *)cookieOfSession
              formDataList:(SAFormDataList *)formDataList
                   success:(void (^)(void))successCallback
                   failure:(void (^)(NSString *errorCode, NSString *errorMessage))failureCallback;

+ (void)uploadDataService:(SARequestParams *)requestParams
                  timeout:(NSTimeInterval)timeout
          cookieOfSession:(NSString *)cookieOfSession
             customerData:(nullable SACustomerData *)customerData
                  address:(nullable SAAddress *)address
             identityData:(nullable SAIdentityData *)identityData
            securityItems:(nullable SASecurityItems *)securityItems
          chipReaderResult:(nullable SAChipReaderResult *)chipReaderResult
verificationResultForChip:(nullable SAVerificationResult *)verificationResultForChip
verificationResultForSelfie:(nullable SAVerificationResult *)verificationResultForSelfie
                  success:(void (^)(void))successCallback
                  failure:(void (^)(NSString *errorCode, NSString *errorMessage))failureCallback;

/**
 * GET api/video-call/availability (SIPMI-23). End'den hemen önce çağrılır; görüntülü görüşmenin o an kullanılabilir olup
 * olmadığını döner. Yanıt zarfı {"error": null | {code, message}, "data": {...}}.
 */
+ (void)videoCallAvailabilityService:(SARequestParams *)requestParams
                             timeout:(NSTimeInterval)timeout
                     cookieOfSession:(NSString *)cookieOfSession
                             success:(void (^)(SAFlowConfigVideoCall *availability))successCallback
                             failure:(void (^)(NSString *errorCode, NSString *errorMessage))failureCallback;

+ (void)finishProcessService:(SARequestParams *)requestParams
                      timeout:(NSTimeInterval)timeout
              cookieOfSession:(NSString *)cookieOfSession
                    kycResult:(SAKycResult *)kycResult
                      success:(void (^)(BOOL status))successCallback
                      failure:(void (^)(NSString *errorCode, NSString *errorMessage))failureCallback;

/**
 * Transaction/End; videoCallEnabled = YES ise "video-call-enabled: true" başlığıyla gönderilir (SIPMI-25). Başlıklı
 * yanıtta videoCallPending (YES = işlem görüntülü görüşmeye bırakıldı, join yapılır; NO = işlem normal kapandı) ve
 * kabul edilmediyse videoCallReason döner. Başlıksız çağrıda videoCallPending nil'dir.
 */
+ (void)finishProcessService:(SARequestParams *)requestParams
                      timeout:(NSTimeInterval)timeout
              cookieOfSession:(NSString *)cookieOfSession
                    kycResult:(SAKycResult *)kycResult
             videoCallEnabled:(BOOL)videoCallEnabled
                      success:(void (^)(BOOL status, NSNumber * _Nullable videoCallPending, NSString * _Nullable videoCallReason))successCallback
                      failure:(void (^)(NSString *errorCode, NSString *errorMessage))failureCallback;

/**
 * Görüntülü görüşme uçları (SIPMI-25): POST api/video-call/join, GET api/video-call/status, POST api/video-call/leave.
 * Hata zarfındaki kod (VC0001…VC0010, SYSTEM_MAINTENANCE) errorCode olarak döner; ağ hatasında NSError kodu.
 * join gövdesi isteğe bağlıdır: consentVersion / consentAt host uygulamadan gelir.
 */
+ (void)videoCallJoinService:(SARequestParams *)requestParams
                     timeout:(NSTimeInterval)timeout
             cookieOfSession:(NSString *)cookieOfSession
              consentVersion:(nullable NSString *)consentVersion
                   consentAt:(nullable NSDate *)consentAt
                     success:(void (^)(SAVideoCallStatus *status))successCallback
                     failure:(void (^)(NSString *errorCode, NSString *errorMessage))failureCallback;

+ (void)videoCallStatusService:(SARequestParams *)requestParams
                       timeout:(NSTimeInterval)timeout
               cookieOfSession:(NSString *)cookieOfSession
                       success:(void (^)(SAVideoCallStatus *status))successCallback
                       failure:(void (^)(NSString *errorCode, NSString *errorMessage))failureCallback;

+ (void)videoCallLeaveService:(SARequestParams *)requestParams
                      timeout:(NSTimeInterval)timeout
              cookieOfSession:(NSString *)cookieOfSession
                      success:(void (^)(SAVideoCallStatus *status))successCallback
                      failure:(void (^)(NSString *errorCode, NSString *errorMessage))failureCallback;

@end

NS_ASSUME_NONNULL_END
