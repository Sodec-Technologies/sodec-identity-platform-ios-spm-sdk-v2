// swift-tools-version:5.9
import PackageDescription

let package = Package(
    name: "sodec-identity-platform-v2-ios-spm",
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
        // SDK'nin calisma aninda bekledigi tek harici kutuphane.
        .package(url: "https://github.com/krzyzanowskim/OpenSSL.git", exact: "3.3.2000")
    ],
    targets: [
        // Onceden derlenmis SDK, GitHub surum dosyasi olarak indirilir.
        // ML Kit, OpenCV, TensorFlow Lite, Lottie ve AFNetworking icinde gomuludur.
        .binaryTarget(
            name: "SAMobileCapture",
            url: "https://github.com/Sodec-Technologies/sodec-identity-platform-v2-ios-spm/releases/download/1.0.1/SAMobileCapture.xcframework.zip",
            checksum: "284d74fdc4100580048be8a718652e2e008e84a69d5fb8aab2291d3e684f81f5"
        ),
        // OpenSSL bagimliligini SDK ile birlikte tasiyan sarmalayici hedef.
        .target(
            name: "SodecIdentityPlatform",
            dependencies: [
                "SAMobileCapture",
                .product(name: "OpenSSL", package: "OpenSSL")
            ]
        )
    ]
)
