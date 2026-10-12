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

#import <SAMobileCapture/SAConfig.h>

NS_INLINE NSString* SALocalizedString(NSString *key, NSString *value)
{
    SAConfig *config = [SAConfig createConfig];
    return [config.bundle localizedStringForKey:key value:@"" table:nil];
}

NS_INLINE NSString* SALocalizedStringWithConfig(SAConfig *config, NSString *key, NSString *value)
{
    return [config.bundle localizedStringForKey:key value:@"" table:nil];
}

#define SALocalizedStringWithFormat(key, ...) [NSString stringWithFormat:SALocalized(key), ##__VA_ARGS__]

NS_INLINE NSString* SALocalized(NSString *key) NS_FORMAT_ARGUMENT(1);
NSString* SALocalized(NSString *key)
{
    SAConfig *config = [SAConfig createConfig];
    return [config.bundle localizedStringForKey:key value:@"" table:nil];
}
