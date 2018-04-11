#
#  Be sure to run `pod spec lint PosTest.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|


  s.name         = "PosTest"
  s.version      = "0.0.1"
  s.summary      = "photo browser for ios."
  s.homepage     = "https://github.com/wkrelease/PosTest"
  s.license      = "MIT"
  s.author             = { "Jewelz Hu" => "18501987683@163.com" }
  s.platform     = :ios, "8.0"
  s.source       = { :git => "https://github.com/wkrelease/PosTest.git", :tag => "0.0.1" }
  s.source_files  = "PosTest", "PosTest/**/*.{h,m}"
  s.frameworks = "XCTest", "UIKit"


end
