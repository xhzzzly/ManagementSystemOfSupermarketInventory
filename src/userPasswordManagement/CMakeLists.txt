add_library(userPasswordManagement STATIC userPasswordManagement.cpp)
target_link_libraries(userPasswordManagement permissionDegree)
target_include_directories(userPasswordManagement INTERFACE ./)