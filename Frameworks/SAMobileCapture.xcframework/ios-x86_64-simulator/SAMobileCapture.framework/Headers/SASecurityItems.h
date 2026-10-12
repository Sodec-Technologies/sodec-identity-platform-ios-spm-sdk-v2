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

@interface SASecurityItems : NSObject

- (id)initWithHologramImage:(UIImage *)hologramImage withHologramDetectionScore:(float)hologramDetectionScore withGhostImage:(UIImage *)ghostImage withGhostDetectionScore:(float)ghostDetectionScore withSignatureImage:(UIImage *)signatureImage withSignatureDetectionScore:(float)signatureDetectionScore withChipImage:(UIImage *)chipImage withChipDetectionScore:(float)chipDetectionScore;

@property (strong, nonatomic, readwrite) UIImage *hologramImage;
@property (nonatomic, assign) float hologramDetectionScore;
@property (strong, nonatomic, readwrite) UIImage *ghostImage;
@property (nonatomic, assign) float ghostDetectionScore;
@property (strong, nonatomic, readwrite) UIImage *signatureImage;
@property (nonatomic, assign) float signatureDetectionScore;
@property (strong, nonatomic, readwrite) UIImage *chipImage;
@property (nonatomic, assign) float chipDetectionScore;

- (NSDictionary *)toDictionary;

@end
