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

#if defined(__has_feature) && __has_feature(modules)
@import UIKit;
#else
#import <UIKit/UIKit.h>
#endif

@interface SALibrary : NSObject

+ (NSString *)getLibraryName;
+ (NSString *)getLibraryVersionCode;
+ (NSString *)getLibraryVersionName;
+ (BOOL)isLibraryDebuggable;
+ (BOOL)isLibraryLoaded;

@end
