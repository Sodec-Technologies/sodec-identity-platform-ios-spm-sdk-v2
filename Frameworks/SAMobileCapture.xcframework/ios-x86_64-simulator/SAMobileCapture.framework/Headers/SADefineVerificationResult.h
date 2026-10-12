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

/**
 * Represents the outcome of a KYC verification process as delivered to the host application.
 *
 * The delivered value depends on the active @c verificationResultMode on @c SAApiManager:
 * - @c SAVerificationResultModePending  → failures yield @c SAVerificationResultTypePending
 * - @c SAVerificationResultModeReject   → failures yield @c SAVerificationResultTypeRejected
 * Successful verifications always yield @c SAVerificationResultTypeApproved.
 */
typedef NS_ENUM(NSInteger, SAVerificationResultType)
{
    /** The verification is awaiting manual review. */
    SAVerificationResultTypePending,
    /** The verification was successful. */
    SAVerificationResultTypeApproved,
    /** The verification was hard-rejected with a specific failure reason. */
    SAVerificationResultTypeRejected
};

/**
 * Defines how a failed KYC result is reported to the host application
 * and presented on the result screen.
 *
 * Configure via @c SAApiManager.verificationResultMode.
 */
typedef NS_ENUM(NSInteger, SAVerificationResultMode)
{
    /**
     * Failed verifications are reported as @c SAVerificationResultTypePending.
     * The result screen shows a "pending manual review" state and the Discover button
     * remains visible. This is the default mode.
     */
    SAVerificationResultModePending,

    /**
     * Failed verifications are reported as @c SAVerificationResultTypeRejected.
     * The result screen shows a hard rejection with a specific header and body message
     * describing the failure reason. The Discover button is hidden.
     */
    SAVerificationResultModeReject
};
