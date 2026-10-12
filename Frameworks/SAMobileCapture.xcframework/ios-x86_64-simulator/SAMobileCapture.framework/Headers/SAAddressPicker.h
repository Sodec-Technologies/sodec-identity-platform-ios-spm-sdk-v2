/*
 * Copyright (C) 2026 Sodec Apps Bilisim Teknolojileri, Inc - All rights reserved
 *
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Hasan Dertli <hasan.dertli@sodecapps.com>
 *
 * Sodec Apps Bilisim Teknolojileri
 * http://sodecapps.com
 * support@sodecapps.com
 */

@class SAAddressPicker;
@class SAAddressItem;

NS_ASSUME_NONNULL_BEGIN

@protocol SAAddressPickerDelegate <NSObject>

@required
- (void)addressPickerDidCancel:(SAAddressPicker *)controller;
- (void)addressPickerDidDone:(SAAddressPicker *)controller
           withSelectedItem:(NSString *)selectedItem
withSubItemsOfSelectedItem:(nullable NSArray<NSString *> *)subItemsOfSelectedItem
       withSubItemsAvailable:(BOOL)subItemsAvailable;

@end

@interface SAAddressPicker : UIViewController

@property (nonatomic, weak, nullable) id<SAAddressPickerDelegate> delegate;

- (instancetype)initWithAddressItems:(NSArray<SAAddressItem *> *)addressItems
                      withParentItem:(nullable NSString *)parentItem
                withSubItemsAvailable:(BOOL)subItemsAvailable;

@end

NS_ASSUME_NONNULL_END
