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

@interface SAFaceParams : NSObject

- (id)init;
- (id)initWithShouldResizeImage:(BOOL)shouldResizeImage withMaxImageSize:(int)maxImageSize withProminentFaceOnly:(BOOL)prominentFaceOnly withReturnDetectedFace:(BOOL)returnDetectedFace;

@property (nonatomic, assign) BOOL shouldResizeImage;
@property (nonatomic, assign) int maxImageSize;
@property (nonatomic, assign) BOOL prominentFaceOnly;
@property (nonatomic, assign) BOOL returnDetectedFace;

@end
