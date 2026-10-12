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

@interface SAKycProcessResult : NSObject

- (id)initWithCountOfTotalItems:(int)countOfTotalItems withCountOfUnsuccessfulItems:(int)countOfUnsuccessfulItems withTotalScore:(float)totalScore;

@property (nonatomic, assign) int countOfTotalItems;
@property (nonatomic, assign) int countOfUnsuccessfulItems;
@property (nonatomic, assign) float totalScore;

- (NSDictionary *)toDictionary;

@end
