cmake_minimum_required(VERSION 3.16)
project(genealogical)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CPP_STANDARD 11)
set(CMAKE_CPP_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wfatal-errors")

add_executable(${CMAKE_PROJECT_NAME}
	src/main.cpp
  	src/core/Person.cpp
	src/core/FamilyManager.cpp
	src/tui/Tui.cpp
)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/include
)