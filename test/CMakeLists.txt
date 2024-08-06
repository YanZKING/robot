add_executable(MotorAngENC util/MotorAngENC.cpp)
target_link_libraries(MotorAngENC hgbot sensorgenius ydlidar_sdk  halgenius rt pthread vmxpi_hal_cpp)



add_executable(testLimit util/testLimit.cpp)
target_link_libraries(testLimit hgbot commandgenius utilgenius sensorgenius ydlidar_sdk  halgenius rt pthread vmxpi_hal_cpp)

add_executable(testServo util/testServo.cpp)
target_link_libraries(testServo hgbot commandgenius utilgenius sensorgenius ydlidar_sdk  halgenius rt pthread vmxpi_hal_cpp)
# set(ROBOT
#   ../src/system/Robot.cpp
# )

add_executable(Seeding Seeding.cpp )
target_link_libraries(Seeding hgbot commandgenius utilgenius sensorgenius ydlidar_sdk  halgenius rt pthread vmxpi_hal_cpp)


add_executable(MotorPIDCommand command/MotorPIDCommand.cpp )
target_link_libraries(MotorPIDCommand hgbot commandgenius utilgenius sensorgenius ydlidar_sdk  halgenius rt pthread vmxpi_hal_cpp)


add_executable(MotorCommand command/MotorCommand.cpp )
target_link_libraries(MotorCommand hgbot commandgenius utilgenius sensorgenius ydlidar_sdk  halgenius rt pthread vmxpi_hal_cpp)

add_executable(SeedCommand command/SeedCommand.cpp )
target_link_libraries(SeedCommand hgbot commandgenius utilgenius sensorgenius ydlidar_sdk  halgenius rt pthread vmxpi_hal_cpp)

add_executable(SeedMoveCommad command/SeedMoveCommad.cpp )
target_link_libraries(SeedMoveCommad hgbot commandgenius utilgenius sensorgenius ydlidar_sdk  halgenius rt pthread vmxpi_hal_cpp)



add_executable(SeedsCommands command/SeedsCommands.cpp )
target_link_libraries(SeedsCommands hgbot commandgenius utilgenius sensorgenius ydlidar_sdk  halgenius rt pthread vmxpi_hal_cpp)

