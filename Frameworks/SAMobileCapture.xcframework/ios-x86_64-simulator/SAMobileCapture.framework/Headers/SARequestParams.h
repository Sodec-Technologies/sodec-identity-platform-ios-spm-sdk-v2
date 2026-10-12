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

@interface SARequestParams : NSObject

- (id)initWithBaseUrl:(NSString *)baseUrl withServiceName:(NSString *)serviceName withSubscriptionId:(NSString *)subscriptionId withSubscriptionKey:(NSString *)subscriptionKey;

@property (strong, nonatomic, readonly) NSString *baseUrl;
@property (strong, nonatomic, readonly) NSString *serviceName;
@property (strong, nonatomic, readonly) NSString *subscriptionId;
@property (strong, nonatomic, readonly) NSString *subscriptionKey;

- (NSString *)getUrl;

@end
