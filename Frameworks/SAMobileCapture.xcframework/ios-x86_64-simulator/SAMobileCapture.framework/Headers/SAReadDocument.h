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

@class SAReadDocument;
@class SAReadDocumentParams;
@class SAReadDocumentResult;

@protocol SAReadDocumentDelegate <NSObject>

@required
- (void)readDocumentDidCancel:(SAReadDocument *)controller;
- (void)readDocumentDidDone:(SAReadDocument *)controller withReadDocumentResult:(SAReadDocumentResult *)readDocumentResult;

@end

@interface SAReadDocument : UIViewController
{
    id<SAReadDocumentDelegate> __unsafe_unretained delegate;
}

@property (unsafe_unretained) id<SAReadDocumentDelegate> delegate;
@property (strong, nonatomic, readwrite) SAReadDocumentParams *readDocumentParams;

@end
