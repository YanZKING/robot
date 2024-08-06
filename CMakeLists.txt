cmake_minimum_required(VERSION 3.10)
set(TMP_PROJECT_NAME "${PROJECT_NAME}")
set(DEFAULT_PROJECT_NAME "high-genius")
if("${TMP_PROJECT_NAME}" STREQUAL "")
    set(TMP_PROJECT_NAME "${DEFAULT_PROJECT_NAME}")
    project(${TMP_PROJECT_NAME})
endif()

include_directories(/usr/local/include/robotgenius)
include_directories(./include)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


# add_executable(testPID testPID.cpp)
# target_link_libraries(testPID  controlgenius commandgenius utilgenius halgenius rt pthread vmxpi_hal_cpp)


# add_executable(testLidar testLidar.cpp)
# target_link_libraries(testLidar  sensorgenius ydlidar_sdk  halgenius rt pthread vmxpi_hal_cpp)

set(ROBOT
  src/system/Robot.cpp
  src/RobotCfg.cpp
  src/command/MotorPIDCommand.cpp
  src/command/SeedCommand.cpp
  src/command/Seed/SeedMoveCommad.cpp
)

add_library(hgbot SHARED ${ROBOT})
target_link_libraries(hgbot controlgenius commandgenius utilgenius sensorgenius ydlidar_sdk  halgenius rt pthread vmxpi_hal_cpp)

add_subdirectory(./test)