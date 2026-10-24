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

#import <SAMobileCapture/SALibrary.h>
#import <SAMobileCapture/SAConfigManager.h>
#import <SAMobileCapture/SAConfig.h>
#import <SAMobileCapture/SAUIConfig.h>
#import <SAMobileCapture/SACropConfig.h>
#import <SAMobileCapture/SAScanConfig.h>
#import <SAMobileCapture/SAAlertConfig.h>
#import <SAMobileCapture/SAToastConfig.h>
#import <SAMobileCapture/SAIndicatorConfig.h>
#import <SAMobileCapture/SAProgressConfig.h>
#import <SAMobileCapture/SANotificationConfig.h>
#import <SAMobileCapture/SATipConfig.h>
#import <SAMobileCapture/SAStepperConfig.h>
#import <SAMobileCapture/SACounterConfig.h>
#import <SAMobileCapture/SAGalleryConfig.h>
#import <SAMobileCapture/SADefineImage.h>
#import <SAMobileCapture/SADefineDocument.h>
#import <SAMobileCapture/SADefineClassification.h>
#import <SAMobileCapture/SADefineIdentity.h>
#import <SAMobileCapture/SADefineAudio.h>
#import <SAMobileCapture/SADefineCapture.h>
#import <SAMobileCapture/SADefineFace.h>
#import <SAMobileCapture/SADefineOCR.h>
#import <SAMobileCapture/SADefineSimilarity.h>
#import <SAMobileCapture/SADefineVideo.h>
#import <SAMobileCapture/SADefineSwipe.h>
#import <SAMobileCapture/SADefineButtonAction.h>
#import <SAMobileCapture/SADefineVerificationResult.h>
#import <SAMobileCapture/SADefineProcessReturn.h>
#import <SAMobileCapture/SADefineKycVerificationResultDisplay.h>
#import <SAMobileCapture/SADefineDetection.h>
#import <SAMobileCapture/SADetectDocument.h>
#import <SAMobileCapture/SAClassifyDocument.h>
#import <SAMobileCapture/SADate.h>
#import <SAMobileCapture/SAReadDocumentParams.h>
#import <SAMobileCapture/SAReadDocumentResult.h>
#import <SAMobileCapture/SAIdentityData.h>
#import <SAMobileCapture/SATTSParams.h>
#import <SAMobileCapture/SACaptureVideoParams.h>
#import <SAMobileCapture/SACaptureVideoResult.h>
#import <SAMobileCapture/SAFaceRecognition.h>
#import <SAMobileCapture/SASpeechRecognition.h>
#import <SAMobileCapture/SAIdentityTypes.h>
#import <SAMobileCapture/SACaptcha.h>
#import <SAMobileCapture/SAViewPdfParams.h>
#import <SAMobileCapture/SASignDocumentParams.h>
#import <SAMobileCapture/SASignatureField.h>
#import <SAMobileCapture/SASignatureFields.h>
#import <SAMobileCapture/SAVideoOutput.h>
#import <SAMobileCapture/SASecurityItems.h>
#import <SAMobileCapture/SAAddress.h>
#import <SAMobileCapture/SAPhotocopyDetectionResult.h>
#import <SAMobileCapture/SAApiManager.h>
#import <SAMobileCapture/SAFlowConfig.h>
#import <SAMobileCapture/SAVideoCallStatus.h>
#import <SAMobileCapture/SAFlowCreator.h>
#import <SAMobileCapture/SARequestBuilder.h>
#import <SAMobileCapture/SARequestParams.h>
#import <SAMobileCapture/SAFaceParams.h>
#import <SAMobileCapture/SAVerificationResult.h>
#import <SAMobileCapture/SAServiceBuilder.h>
#import <SAMobileCapture/SAAddressItem.h>
#import <SAMobileCapture/SACustomerData.h>
#import <SAMobileCapture/SAFormData.h>
#import <SAMobileCapture/SAFormDataList.h>
#import <SAMobileCapture/SAKycProcessResult.h>
#import <SAMobileCapture/SAKycResult.h>
#import <SAMobileCapture/SAOpenSSLWrapper.h>
#import <SAMobileCapture/SAChipReaderUtility.h>
#import <SAMobileCapture/SACustomerVerification.h>
#import <SAMobileCapture/SAChipVerification.h>
#import <SAMobileCapture/SABiometricVerification.h>
#import <SAMobileCapture/SAStartAddressVerification.h>
#import <SAMobileCapture/SAAddressVerification.h>
#import <SAMobileCapture/SAAddressPicker.h>
#import <SAMobileCapture/SAFinishCustomerVerification.h>
#import <SAMobileCapture/SACaptureDocument.h>
#import <SAMobileCapture/SAProcessDocument.h>
#import <SAMobileCapture/SAVerifyDocument.h>
#import <SAMobileCapture/SAReadDocument.h>
#import <SAMobileCapture/SASinglePage.h>
#import <SAMobileCapture/SACropDocument.h>
#import <SAMobileCapture/SAFolioPage.h>
#import <SAMobileCapture/SAViewDocument.h>
#import <SAMobileCapture/SACaptureSelfie.h>
#import <SAMobileCapture/SACaptureVideo.h>
#import <SAMobileCapture/SAViewPdf.h>
#import <SAMobileCapture/SASignDocument.h>
#import <SAMobileCapture/SACrypto.h>
#import <SAMobileCapture/SAFileManager.h>
#import <SAMobileCapture/SASizeCalculator.h>
#import <SAMobileCapture/SACreatePDF.h>
#import <SAMobileCapture/SACreateFolio.h>
#import <SAMobileCapture/SAImageLoader.h>
#import <SAMobileCapture/SADataLoader.h>
#import <SAMobileCapture/SAString.h>
#import <SAMobileCapture/SASimilarity.h>
#import <SAMobileCapture/SALocalization.h>
#import <SAMobileCapture/SAUIUtility.h>
#import <SAMobileCapture/SAIdentityUtility.h>
#import <SAMobileCapture/SAConnection.h>
