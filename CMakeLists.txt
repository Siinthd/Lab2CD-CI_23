cmake_minimum_required(VERSION 3.10)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(ip_filter VERSION ${PROJECT_VERSION})

# configure directories
set(SOURCE_PATH "${PROJECT_SOURCE_DIR}/src")
set(TEST_PATH "${PROJECT_SOURCE_DIR}/test")

find_package(GTest REQUIRED)

add_executable(ip_filter ${SOURCE_PATH}/main.cpp)
add_library(filter ${SOURCE_PATH}/filter.cpp)
add_executable(test_filter ${TEST_PATH}/test_filter.cpp)
set_target_properties(ip_filter filter PROPERTIES
		CXX_STANDART 14
		CXX_STANDART_REQUIRED ON
		)


target_include_directories(filter PRIVATE "${CMAKE_BINARY_DIR}")

set_target_properties(test_filter PROPERTIES
		INCLUDE_DIRECTORIES ${GTEST_INCLUDE_DIRS})
target_link_libraries(ip_filter PRIVATE filter)

target_link_libraries(test_filter filter GTest::gtest_main)
install(TARGETS ip_filter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT razelim@list.ru)

include(CPack)

enable_testing()
include(GoogleTest)
gtest_discover_tests(test_filter)


