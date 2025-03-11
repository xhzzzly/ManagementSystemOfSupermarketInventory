add_library(mainMenu STATIC mainMenu.c)
target_link_libraries(mainMenu permissionDegree
                               productInformationManagement
                               inventoryManagement
                               userPasswordManagement
                               dataReadingAndStorage)
target_include_directories(mainMenu INTERFACE ./)