#import <Foundation/Foundation.h>
#import <OpenSSL/evp.h>
#import <OpenSSL/x509.h>
#import <OpenSSL/x509_vfy.h>
#import <OpenSSL/safestack.h>

NS_ASSUME_NONNULL_BEGIN

@interface SAOpenSSLWrapper : NSObject

+ (int)getKeyType:(EVP_PKEY * _Nullable)key;
+ (int)getCertChainLength:(STACK_OF(X509) * _Nullable)chain;
+ (X509 * _Nullable)getCertFromChain:(STACK_OF(X509) * _Nullable)chain atIndex:(int)index;

@end

NS_ASSUME_NONNULL_END
