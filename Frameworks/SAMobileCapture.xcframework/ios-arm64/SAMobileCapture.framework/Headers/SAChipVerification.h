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
@class SADate;
@protocol SAKycStepDelegate;

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(ios(13))
@interface SAChipVerification : UIViewController

@property (nonatomic, strong)           SAApiManager    *apiManager;
@property (nonatomic, strong, nullable) SAIdentityData  *fullIdentityData;
@property (nonatomic, copy,   nullable) NSString        *identityFaceId;
@property (nonatomic, copy,   nullable) NSString        *sessionCookie;
@property (nonatomic, strong, nullable) SACustomerData  *customerData;
@property (nonatomic, strong, nullable) SASecurityItems *securityItems;
@property (nonatomic, strong, nullable) UIImage         *barcodeImage;
@property (nonatomic, copy,   nullable) NSString        *barcodeResult;

/** Delegate for dynamic KYC orchestration. Weak reference to SACustomerVerification. */
@property (nonatomic, weak, nullable) id<SAKycStepDelegate> stepDelegate;

- (instancetype)initWithBirthDate:(SADate *)birthDate
                   withSerialNumber:(NSString *)serialNumber
                 withExpirationDate:(SADate *)expirationDate
                 withIsIDCardTurkish:(BOOL)isIDCardTurkish;

@end

NS_ASSUME_NONNULL_END
