add_library(logInSystem STATIC logInSystem.cpp)
target_link_libraries(logInSystem permissionDegree)

target_include_directories(logInSystem INTERFACE ./)