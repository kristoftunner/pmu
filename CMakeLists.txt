include(ExternalProject)
cmake_minimum_required(VERSION 3.12)

project(pmuc CXX)


set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")


message(STATUS "PWD: ${CMAKE_CURRENT_SOURCE_DIR}")
set(STAGING_DIR "${CMAKE_CURRENT_SOURCE_DIR}/build")
message(STATUS "PWD: ${STAGING_DIR}")

###################### Libraries ###################
ExternalProject_Add(spdlog
    PREFIX spdlog
    SOURCE_DIR ${PROJECT_SOURCE_DIR}/ext/spdlog
    CMAKE_ARGS -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
    -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
    -DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}
    -DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE}
    -DCMAKE_INSTALL_PREFIX=${STAGING_DIR}
    -DSPDLOG_BUILD_SHARED=OFF
)

set(SRC_FILES
    src/Log.cpp
)

add_library(${PROJECT_NAME} ${SRC_FILES})

add_subdirectory(ext/gtest)

#################### Executable ##################
target_include_directories(${PROJECT_NAME} 
    PUBLIC ext/spdlog/include
    PUBLIC ${STAGING_DIR}/include/
    PUBLIC ext/gtest/googletest/include
    )

add_dependencies(${PROJECT_NAME} spdlog)

add_executable(${PROJECT_NAME}_runner src/main.cpp)

target_link_libraries(${PROJECT_NAME}_runner ${PROJECT_NAME})

#################### Test files ##################
set(TEST_FILES
    test/BufferTest.cpp
)

add_executable(${PROJECT_NAME}_test ${TEST_FILES})
target_include_directories(${PROJECT_NAME}_test 
    PUBLIC ext/gtest/googletest/include
)
target_link_libraries(${PROJECT_NAME}_test 
    ${PROJECT_NAME}
    gtest_main
)

#add_test(
#    NAME ${PROJECT_NAME}
#    COMMAND ${PROJECT_NAME}
#)