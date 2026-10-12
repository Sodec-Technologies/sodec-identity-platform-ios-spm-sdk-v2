/*
 * Copyright (C) 2026 Sodec Apps Bilisim Teknolojileri, Inc - All rights reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Hasan Dertli <hasan.dertli@sodecapps.com>
 *
 * Sodec Apps Bilisim Teknolojileri
 * http://sodecapps.com
 * support@sodecapps.com
 */

@class SAApiManager;
@class SAIdentityData;
@class SACustomerData;
@class SASecurityItems;
@class SAChipReaderResult;
@class SAVerificationResult;
@protocol SAKycStepDelegate;

NS_ASSUME_NONNULL_BEGIN

@interface SABiometricVerification : UIViewController

@property (nonatomic, strong)         SAApiManager       *apiManager;
@property (nonatomic, strong, nullable) SAIdentityData   *fullIdentityData;
@property (nonatomic, copy,   nullable) NSString         *identityFaceId;
@property (nonatomic, copy,   nullable) NSString         *sessionCookie;
@property (nonatomic, strong, nullable) SACustomerData   *customerData;
@property (nonatomic, strong, nullable) SASecurityItems  *securityItems;
@property (nonatomic, strong, nullable) UIImage          *barcodeImage;
@property (nonatomic, copy,   nullable) NSString         *barcodeResult;
@property (nonatomic, strong, nullable) SAChipReaderResult    *chipReaderResult;
@property (nonatomic, copy,   nullable) NSString              *chipFaceId;
@property (nonatomic, strong, nullable) SAVerificationResult  *chipVerificationResult;
@property (nonatomic, assign)           BOOL                   nfcFailed;

/** Delegate for dynamic KYC orchestration. Weak reference to SACustomerVerification. */
@property (nonatomic, weak, nullable) id<SAKycStepDelegate> stepDelegate;

@end

NS_ASSUME_NONNULL_END
