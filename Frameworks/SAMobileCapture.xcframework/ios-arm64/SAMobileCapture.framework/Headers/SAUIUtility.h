/*
 * Copyright (C) 2026 Sodec Apps Bilisim Teknolojileri, Inc. - All rights reserved.
 *
 * This source code and all associated files are the confidential and proprietary property
 * of Sodec Apps Bilisim Teknolojileri, Inc. Unauthorized copying, distribution, or disclosure
 * of this file, via any medium, is strictly prohibited.
 *
 * This software is protected under international copyright and intellectual property laws.
 * Use of this software is subject to the terms of a valid license agreement with
 * Sodec Apps Bilisim Teknolojileri, Inc.
 *
 * Proprietary and confidential.
 * Written by Hasan Dertli <hasan.dertli@sodec.com>
 *
 * Sodec Apps Bilisim Teknolojileri, Inc.
 * https://sodec.com
 * support@sodec.com
 */

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface SAUIUtility : NSObject

+ (CGFloat)getStatusBarHeight;
+ (BOOL)isBottomBackgroundAvailable;
+ (CGFloat)getBottomBackgroundHeight;
+ (void)setInterfaceOrientationToPortrait;
+ (void)setInterfaceOrientationToLandscape;
+ (void)setUserInterfaceStyleToLight:(UIView *)view;

/**
 * Returns the named circled-number asset (e.g. "sa_circled_1") from the given bundle.
 * If the asset is not found (e.g. "sa_circled_4" which ships without a PNG),
 * the image is generated programmatically using Core Graphics so the UI is
 * never left with a missing icon.
 *
 * @param number  Step number to display inside the circle (1–9).
 * @param bundle  The bundle to search first; falls back to the main bundle.
 * @return        A template-mode UIImage of a filled circle containing the number.
 */
+ (UIImage *)circledStepNumberImage:(NSInteger)number bundle:(nullable NSBundle *)bundle;

NS_ASSUME_NONNULL_END

@end
