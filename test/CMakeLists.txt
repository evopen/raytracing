set(BINARY ${CMAKE_PROJECT_NAME}_test)

file(GLOB_RECURSE TEST_SOURCES "*.cpp")
set(RAYTRACER_SOURCES ${SOURCE_DIR}/vec3.cpp)
message(${RAYTRACER_SOURCES})

add_executable(${BINARY} ${TEST_SOURCES} ${RAYTRACER_SOURCES})

find_package(GTest CONFIG REQUIRED)
target_link_libraries(${BINARY} PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

target_include_directories(${BINARY} PRIVATE ${SOURCE_DIR})

include(GoogleTest)
gtest_discover_tests(${BINARY})
