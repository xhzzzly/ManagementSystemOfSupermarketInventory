add_library(mainMenu STATIC mainMenu.cpp)
target_link_libraries(mainMenu permissionDegree)
target_include_directories(mainMenu INTERFACE ./)