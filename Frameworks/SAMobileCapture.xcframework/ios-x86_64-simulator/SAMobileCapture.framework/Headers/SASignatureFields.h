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

@class SASignatureField;

@interface SASignatureFields : NSObject

- (id)init;
- (id)initWithMessage:(NSString *)message;

@property (strong, nonatomic, readonly) NSMutableArray *signatureFields;
@property (strong, nonatomic, readwrite) NSString *signatureMessage;

- (void)addSignatureField:(SASignatureField *)signatureField;
- (SASignatureField *)getSignatureFieldAtIndex:(int)index;
- (NSUInteger)countOfSignatureFields;

@end
