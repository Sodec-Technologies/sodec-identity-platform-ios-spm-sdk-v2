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

@class SAFormData;

@interface SAFormDataList : NSObject

- (id)init;

@property (strong, nonatomic, readonly) NSMutableArray *formDataList;

- (void)addFormData:(SAFormData *)formData;
- (SAFormData *)getFormDataAtIndex:(int)index;
- (NSUInteger)countOfFormDataList;

@end
