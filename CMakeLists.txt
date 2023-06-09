cmake_minimum_required (VERSION 3.26)

set(PROJECT_NAME TopSystem)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/src/icon/app.rc")

set(SOURCES 
	TopSystem.cpp 
	src/Graphics.cpp 
	src/Point2D.cpp 
	src/Vector2D.cpp 
	src/Shape.cpp 
	src/Triangle.cpp 
	src/Rectangle.cpp 
	src/Circle.cpp 
	src/Controller.cpp)

set(HEADERS 
	src/Constants.h 
	src/Graphics.h 
	src/Point2D.h 
	src/Vector2D.h 
	src/Shape.h 
	src/Triangle.h 
	src/Rectangle.h 
	src/Circle.h 
	src/Controller.h)

project(${PROJECT_NAME} CXX)
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${APP_ICON_RESOURCE_WINDOWS})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})