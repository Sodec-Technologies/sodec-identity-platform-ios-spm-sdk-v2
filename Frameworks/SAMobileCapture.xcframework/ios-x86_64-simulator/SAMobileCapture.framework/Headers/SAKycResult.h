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

@class SAKycProcessResult;

@interface SAKycResult : NSObject

- (id)initWithStatus:(BOOL)status withCodeOfFailedStatus:(NSString *)codeOfFailedStatus withMessageOfFailedStatus:(NSString *)messageOfFailedStatus withIdentityVerificationProcessResult:(SAKycProcessResult *)identityVerificationProcessResult withChipVerificationProcessResult:(SAKycProcessResult *)chipVerificationProcessResult;

@property (nonatomic, assign) BOOL status;
@property (strong, nonatomic, readwrite) NSString *codeOfFailedStatus;
@property (strong, nonatomic, readwrite) NSString *messageOfFailedStatus;
@property (strong, nonatomic, readwrite) SAKycProcessResult *identityVerificationProcessResult;
@property (strong, nonatomic, readwrite) SAKycProcessResult *chipVerificationProcessResult;

/**
 * Custom failure header text populated by @c SAKyc when
 * @c SAVerificationResultModeReject is active. @c nil for success or PENDING mode.
 */
@property (strong, nonatomic, readwrite, nullable) NSString *headerText;

/**
 * Custom failure body text populated by @c SAKyc when
 * @c SAVerificationResultModeReject is active. @c nil for success or PENDING mode.
 */
@property (strong, nonatomic, readwrite, nullable) NSString *bodyText;

/**
 * Görüntülü görüşmeyle sonuçlanan işlemde görüşmenin bitiş durumu (APPROVED / REJECTED / EXPIRED / DROPPED /
 * ABANDONED) ve müşteriye gösterilebilir gerekçe kodu (SIPMI-27). Görüşme yapılmadıysa nil. Nihai karar görüşmede
 * verildiği için onay dışındaki her sonuç SAVerificationResultTypeRejected olarak bildirilir.
 */
@property (strong, nonatomic, readwrite, nullable) NSString *videoCallResult;
@property (strong, nonatomic, readwrite, nullable) NSString *videoCallReasonCode;

- (NSDictionary *)toDictionary;

@end
