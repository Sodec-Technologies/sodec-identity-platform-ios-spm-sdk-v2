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
        // Onceden derlenmis SDK (yerel sembolleri ayiklanmis; GitHub'in 100 MB dosya sinirinin altinda).
        // ML Kit, OpenCV, TensorFlow Lite, Lottie ve AFNetworking icinde gomuludur.
        .binaryTarget(
            name: "SAMobileCapture",
            path: "Frameworks/SAMobileCapture.xcframework"
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
