add_library(logInSystem STATIC logInSystem.cpp)

target_link_libraries(logInSystem permissionDegree userPasswordManagement)

target_include_directories(logInSystem INTERFACE ./)