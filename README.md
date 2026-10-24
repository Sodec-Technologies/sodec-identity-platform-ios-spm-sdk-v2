# Sodec Identity Platform v2 — iOS SDK (Swift Package Manager)

## Erişim

Paket gizli bir GitHub deposundadır. Xcode'da **Settings → Source Control → Accounts → + → GitHub** adımıyla, Sodec'in size ilettiği hesap adı ve erişim anahtarıyla (token) giriş yapın.

## Kurulum

Xcode: **File → Add Package Dependencies…** ve şu adresi girin:

```
https://github.com/Sodec-Technologies/sodec-identity-platform-ios-spm-sdk-v2.git
```

Sürüm kuralı olarak **Exact Version** seçip `1.0.2-beta.1` yazın ve `SodecIdentityPlatform` ürününü uygulama hedefinize ekleyin.

## Kullanım

```swift
import SodecIdentityPlatform
```

## Gereksinimler

- iOS 15.6 ve üzeri
- Gerçek cihaz: arm64. Simülatör: yalnızca x86_64 (Apple Silicon Mac'lerde Rosetta gerekir).
- Xcode 27 ile derlenen uygulamalarda UIScene yaşam döngüsü zorunludur (Apple gereksinimi).

© 2026 Sodec Apps Bilisim Teknolojileri, Inc. — support@sodec.com
