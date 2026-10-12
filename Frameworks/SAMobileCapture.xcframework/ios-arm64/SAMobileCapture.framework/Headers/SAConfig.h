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

@interface SAConfig : NSObject

@property (nonatomic, assign) BOOL debuggable;
@property (strong, nonatomic, readwrite) NSString *language;
@property (strong, nonatomic, readonly) NSBundle *bundle;

+ (SAConfig *)createConfig;

@end
