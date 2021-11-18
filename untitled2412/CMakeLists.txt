cmake_minimum_required(VERSION 3.10)
project(helloworld)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "C:\\Qt\\6.1.0\\mingw81_64\\lib\\cmake")

find_package(Qt6Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(helloworld main.cpp GUI/SecondMenu/SecondMenu.cpp GUI/Third_Menu/ThirdMenu.cpp validator/domain_validator.cpp validator/domain_validator.h validator/file_validator.cpp validator/file_validator.h validator/repository_validator.h validator/repository_validator.cpp service/database_service.cpp service/database_service.h service/watchlist_service.cpp service/watchlist_service.h repository/watchlist_file_repository.cpp repository/watchlist_repository.cpp repository/watchlist_repository.h repository/database_file_repository.cpp repository/database_file_repository.h repository/database_repository.cpp repository/database_repository.h  ui/ui.cpp ui/ui.h domain/domain.cpp domain/domain.h GUI/SecondMenu/SecondMenu.h GUI/Third_Menu/ThirdMenu.cpp GUI/Third_Menu/ThirdMenu.h GUI/FirstMenu/FirstMenu.cpp GUI/FirstMenu/FirstMenu.h GUI/FirstMenu/Functionalities.cpp GUI/FirstMenu/Functionalities.h GUI/GuiFunctions/GuiFunctions.cpp GUI/GuiFunctions/GuiFunctions.h)
target_link_libraries(helloworld Qt6::Widgets)