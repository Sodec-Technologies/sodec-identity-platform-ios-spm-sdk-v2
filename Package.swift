// swift-tools-version:5.9
import PackageDescription

let package = Package(
    name: "sodec-identity-platform-v2",
    platforms: [
        .iOS("15.6")
    ],
    products: [
        .library(
            name: "SodecIdentityPlatform",
            targets: ["SodecIdentityPlatform"]
        )
    ],
    dependencies: [
        // SDK'nin calisma aninda bekledigi harici kutuphaneler.
        .package(url: "https://github.com/krzyzanowskim/OpenSSL.git", exact: "3.3.2000"),
        // Goruntulu gorusme (SIPMI-22): LiveKitClient 2.17.0 kodu SDK icinde gomulu; dinamik WebRTC ve UniFFI
        // ikilileri SDK ile ayni surumde (LiveKitClient 2.17.0'in sabitledigi) uygulamaya eklenir.
        .package(url: "https://github.com/livekit/webrtc-xcframework.git", exact: "150.7871.02"),
        .package(url: "https://github.com/livekit/livekit-uniffi-xcframework.git", exact: "0.1.9")
    ],
    targets: [
        // Onceden derlenmis SDK. ML Kit, OpenCV, TensorFlow Lite, Lottie, AFNetworking ve LiveKitClient icinde gomuludur.
        .binaryTarget(
            name: "SAMobileCapture",
            path: "Frameworks/SAMobileCapture.xcframework"
        ),
        // OpenSSL ve goruntulu gorusme ikililerini SDK ile birlikte tasiyan sarmalayici hedef.
        .target(
            name: "SodecIdentityPlatform",
            dependencies: [
                "SAMobileCapture",
                .product(name: "OpenSSL", package: "OpenSSL"),
                .product(name: "LiveKitWebRTC", package: "webrtc-xcframework"),
                .product(name: "LiveKitUniFFI", package: "livekit-uniffi-xcframework")
            ]
        )
    ]
)
