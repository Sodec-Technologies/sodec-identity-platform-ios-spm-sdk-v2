/*
 * Copyright (C) 2026 Sodec Apps Bilisim Teknolojileri, Inc - All rights reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Sodec Apps Bilisim Teknolojileri
 * http://sodecapps.com
 * support@sodecapps.com
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// Görüşme durumları (sözleşme: docs/video-call-sdk-api.md §1)
extern NSString * const SAVideoCallStatusQueued;     // "QUEUED"
extern NSString * const SAVideoCallStatusAssigned;   // "ASSIGNED"
extern NSString * const SAVideoCallStatusInCall;     // "IN_CALL"
extern NSString * const SAVideoCallStatusApproved;   // "APPROVED"
extern NSString * const SAVideoCallStatusRejected;   // "REJECTED"
extern NSString * const SAVideoCallStatusAbandoned;  // "ABANDONED"
extern NSString * const SAVideoCallStatusDropped;    // "DROPPED"
extern NSString * const SAVideoCallStatusExpired;    // "EXPIRED"

/// status yanıtındaki connection: odaya bağlanma bilgisi (ASSIGNED / IN_CALL).
@interface SAVideoCallConnection : NSObject

@property (nonatomic, copy)   NSString  *url;
@property (nonatomic, copy)   NSString  *token;
@property (nonatomic, copy)   NSString  *roomName;
@property (nonatomic, copy)   NSString  *identity;
@property (nonatomic, assign) NSInteger  tokenExpiresInSeconds;
/// Tenant yayın kalitesi profili (yoksa 0; istemci varsayılanı kullanılır).
@property (nonatomic, assign) NSInteger  videoWidth;
@property (nonatomic, assign) NSInteger  videoHeight;
@property (nonatomic, assign) NSInteger  videoFrameRate;
@property (nonatomic, assign) NSInteger  videoMaxBitrateKbps;

@end

/// Bitmiş görüşmenin sonucu.
@interface SAVideoCallResult : NSObject

/// APPROVED / REJECTED / EXPIRED / DROPPED / ABANDONED
@property (nonatomic, copy)             NSString *result;
/// Müşteriye gösterilebilir genel gerekçe kodu; onayda nil (sözleşme §4).
@property (nonatomic, nullable, copy)   NSString *reasonCode;
/// Müşteriye gösterilebilir mesaj (sunucudan gelir).
@property (nonatomic, copy)             NSString *message;

@property (nonatomic, readonly)         BOOL      isApproved;

/// Sonuç ekranı başlığı (yerelleştirilmiş).
@property (nonatomic, readonly)         NSString *displayTitle;
/// Sonuç ekranı metni: bilinen gerekçe kodu için yerelleştirilmiş metin, değilse sunucu mesajı (sözleşme §4).
@property (nonatomic, readonly)         NSString *displayMessage;

@end

/// join / status / leave yanıtının data alanı.
@interface SAVideoCallStatus : NSObject

@property (nonatomic, assign)           long long              videoCallId;
@property (nonatomic, copy)             NSString              *status;
@property (nonatomic, assign)           BOOL                   isFinal;
@property (nonatomic, nullable, strong) NSNumber              *queuePosition;
@property (nonatomic, nullable, strong) NSNumber              *estimatedWaitSeconds;
@property (nonatomic, nullable, strong) NSNumber              *expiresInSeconds;
@property (nonatomic, assign)           NSInteger              pollIntervalSeconds;
@property (nonatomic, nullable, strong) SAVideoCallConnection *connection;
@property (nonatomic, nullable, strong) SAVideoCallResult     *result;

+ (nullable SAVideoCallStatus *)fromDictionary:(nullable NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
