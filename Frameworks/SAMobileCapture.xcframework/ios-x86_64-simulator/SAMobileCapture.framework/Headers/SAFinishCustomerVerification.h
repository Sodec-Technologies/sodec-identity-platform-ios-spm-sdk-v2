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

@class SAKycResult;
@class SAApiManager;

NS_ASSUME_NONNULL_BEGIN

@interface SAFinishCustomerVerification : UIViewController

/** API manager passed through from the orchestrator. Used for UI configuration. */
@property (nonatomic, strong, nullable) SAApiManager *apiManager;

- (instancetype)initWithKycResult:(SAKycResult *)kycResult;

@end

NS_ASSUME_NONNULL_END
