cmake_minimum_required(VERSION 3.5)
project(test_wayland VERSION 0.1 LANGUAGES CXX)

find_package(ECM 5.30 REQUIRED NO_MODULE)

include(FeatureSummary)

# where to look first for cmake modules, before ${CMAKE_ROOT}/Modules/ is checked
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR})

find_package(EGL)
find_package(Wayland 1.2 REQUIRED COMPONENTS Client Cursor Egl)

add_executable(test_wayland main.cpp)

target_link_libraries(test_wayland Wayland::Client)

install(TARGETS test_wayland RUNTIME DESTINATION bin)

feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)
