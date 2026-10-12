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

typedef NS_ENUM(NSInteger, SAImageQuality)
{
    SAImageQualityDefault,
    SAImageQualityMedium,
    SAImageQualityLow,
    SAImageQualityHigh,
    SAImageQualityExtraHigh
};

typedef NS_ENUM(NSInteger, SAImageEnhancing)
{
    SAImageEnhancingDefault,
    SAImageEnhancingNone,
    SAImageEnhancingAutoColor,
    SAImageEnhancingWhiteBoard
};

typedef NS_ENUM(NSInteger, SAImageFilter)
{
    SAImageFilterDefault,
    SAImageFilterColor,
    SAImageFilterGrayscale
};

typedef NS_ENUM(NSInteger, SAImageFormat)
{
    SAImageFormatDefault,
    SAImageFormatJPEG,
    SAImageFormatPNG
};
