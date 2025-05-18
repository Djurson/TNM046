cmake_minimum_required(VERSION 3.25.0)
project(tnm046-labs VERSION 1.0.0 DESCRIPTION "TNM046 OpenGL Labs" LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

function(enable_warnings target)
target_compile_options(${target} PUBLIC 
$<$<CXX_COMPILER_ID:MSVC>:/W4 /permissive->
$<$<CXX_COMPILER_ID:AppleClang>:-Wall -Wextra -Wconversion>
$<$<CXX_COMPILER_ID:Clang>:-Wall -Wextra -Wconversion>
$<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra -Wconversion>
)
endfunction()

find_package(OpenGL REQUIRED)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(glfw-3.4)

set(HEADER_FILES
	Rotator.hpp
	Shader.hpp
	Texture.hpp
	TriangleSoup.hpp
	Utilities.hpp
)

set(SOURCE_FILES
	GLprimer.cpp
	Rotator.cpp
	Shader.cpp
	Texture.cpp
	TriangleSoup.cpp
	Utilities.cpp
)

add_executable(tnm046-labs ${SOURCE_FILES} ${HEADER_FILES})
enable_warnings(tnm046-labs)

if(MSVC AND TARGET tnm046-labs)
	set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT tnm046-labs)
	set_property(TARGET tnm046-labs PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
elseif(CMAKE_GENERATOR MATCHES "Xcode"
	AND ${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.15.0"
	AND TARGET tnm046-labs)
	set_target_properties(tnm046-labs PROPERTIES
		XCODE_GENERATE_SCHEME TRUE
		XCODE_SCHEME_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
	)
endif()

target_compile_definitions(tnm046-labs PRIVATE $<$<CXX_COMPILER_ID:MSVC>:_CRT_SECURE_NO_WARNINGS>)

target_link_libraries(tnm046-labs PRIVATE OpenGL::GL glfw)

option(TNM046_USE_EXTERNAL_GLEW "GLEW is provided externaly" OFF)
# Set CMake to prefere Vendor gl libraries rather than legacy, fixes warning on some unix systems
if(NOT TNM046_USE_EXTERNAL_GLEW)
	set(OpenGL_GL_PREFERENCE GLVND) 
	add_subdirectory(glew)
	target_link_libraries(tnm046-labs PUBLIC tnm046::GLEW)
else()
	find_package(GLEW REQUIRED)
	target_link_libraries(tnm046-labs PUBLIC GLEW::GLEW)
endif()
