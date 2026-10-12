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

@interface SAFormData : NSObject

- (id)initWithFileData:(NSData *)fileData withName:(NSString *)name withFileName:(NSString *)fileName withMimeType:(NSString *)mimeType;

@property (strong, nonatomic, readwrite) NSData *fileData;
@property (strong, nonatomic, readwrite) NSString *name;
@property (strong, nonatomic, readwrite) NSString *fileName;
@property (strong, nonatomic, readwrite) NSString *mimeType;

@end
