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

#import <SAMobileCapture/SAApiManager.h>
#import <SAMobileCapture/SAFlowCreator.h>

NS_ASSUME_NONNULL_BEGIN

@interface SACustomerVerification : UIViewController

@property (nonatomic, weak, nullable) id<SACustomerVerificationDelegate> delegate;
@property (nonatomic, strong)         SAApiManager *apiManager;
@property (nonatomic, copy, nullable) NSString     *identityNumber;
@property (nonatomic, copy, nullable) NSString     *token;
@property (nonatomic, assign)         BOOL          isServiceTypeID;

/**
 * Client-defined flow configuration set by @c SAApiManager when the caller uses
 * @c createCustomerVerification:withToken:flowCreator: or
 * @c createCustomerVerification:withIdentityNumber:flowCreator:.
 *
 * For SDK internal use only. Do not set this property directly; pass an
 * @c SAFlowCreator to the factory method instead.
 *
 * Whether this configuration is used depends on @c SAApiManager.allowServerToOverrideFlow.
 * When @c nil, the SDK falls back to server config or legacy behaviour.
 */
@property (nonatomic, strong, nullable) SAFlowCreator *clientFlowCreator;

@end

NS_ASSUME_NONNULL_END
