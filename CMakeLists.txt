# CMAKE file for EDGITOR by Alepacho and keithcodes :: altered for DODECA

cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Check if we should use vcpkg from the boostrap script
if (EXISTS "${CMAKE_CURRENT_LIST_DIR}/bootstrap/vcpkg")
	if (DEFINED ENV{VCPKG_ROOT})
		message(WARNING "Overriding system-wide VCPKG_ROOT value with boostrap folder's vcpkg install")
	endif()

	set(ENV{VCPKG_ROOT} "${CMAKE_CURRENT_LIST_DIR}/bootstrap/vcpkg")
endif()

# Checks if vcpkg is installed, and if so sets the cmake toolchain file to the one provided by vcpkg
if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
	set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
	message(STATUS "Using vcpkg CMake toolchain at ${CMAKE_TOOLCHAIN_FILE}")
elseif(NOT DEFINED ENV{VCPKG_ROOT})
	message(WARNING "VCPKG_ROOT env variable not set, can't automatically determine vcpkg CMake toolchain file. You can ignore this if you're not using vcpkg for project libraries.")
	message(WARNING "Either set the system environment variable VCPKG_ROOT to your vcpkg installation directory, or add the -DCMAKE_TOOLCHAIN_FILE=/my/vcpkg/dir variable to the CMake profile.")
endif()

# Check if vcpkg is enabled and sets the appropriate platform triplet
if (DEFINED ENV{VCPKG_ROOT} AND DEFINED CMAKE_TOOLCHAIN_FILE)
	if (NOT DEFINED VCPKG_TARGET_TRIPLET)
		if (WIN32)
			if (CMAKE_BUILD_TYPE STREQUAL "Debug")
				# Uses static libraries with debug symbols
				set(VCPKG_TARGET_TRIPLET "x64-windows-static-md" CACHE STRING "")
			else()
				# Uses static libraries
				set(VCPKG_TARGET_TRIPLET "x64-windows-static" CACHE STRING "")
			endif()
		elseif(UNIX)
			set(VCPKG_TARGET_TRIPLET "x64-linux" CACHE STRING "")
		else()
			message(ERROR "Failed to determine appropriate VCPKG_TARGET_TRIPLET value for your platform, please set the VCPKG_TARGET_TRIPLET environment variables")
		endif()
	endif()

	message(STATUS "Using vcpkg triplet toolchain ${VCPKG_TARGET_TRIPLET}")
endif()

project(DODECA)

file(GLOB SOURCE
	${PROJECT_SOURCE_DIR}/src/core/*.cpp
	${PROJECT_SOURCE_DIR}/src/core/*.h
)

foreach(source_i IN LISTS SOURCE)
    get_filename_component(source_path "${source_i}" PATH)

    string(REPLACE "${PROJECT_SOURCE_DIR}/src/core" "" source_path_rel "${source_path}")

    string(REPLACE "/" "\\" source_path_msvc "${source_path_rel}")

    # Group into "UIBOXES" if its in the name
    string(FIND "${source_i}" "UIBOX" OUT)
    if(OUT GREATER -1)
       set(source_path_msvc "UIBOXES\\${source_path_msvc}")
    endif()

    # Group into "Source Files" and "Header Files"
    if ("${source_i}" MATCHES ".*\\.cpp")
       set(GROUP "Source Files\\${source_path_msvc}")
    elseif("${source_i}" MATCHES ".*\\.h")
       set(GROUP "Header Files\\${source_path_msvc}")
    endif()


    source_group("${GROUP}" FILES "${source_i}")
endforeach()


add_executable(${PROJECT_NAME} ${SOURCE})

if(UNIX)
	target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -lstdc++fs)
elseif(MSVC)
	target_compile_options(${PROJECT_NAME} PRIVATE /W4 /permissive-)
endif()

# Find the system OpenGL library
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${OPENGL_LIBRARIES})

# Find the SDL2 library from vcpkg
find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2main SDL2::SDL2-static)

# Find the SDL2-image library from vcpkg
find_package(sdl2-image CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2_image)

# Find the SDL2-ttf library from vcpkg
find_package(sdl2-ttf CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2_ttf)

# Copy the resources folder into the build directory
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory
		${CMAKE_SOURCE_DIR}/res/ $<TARGET_FILE_DIR:${PROJECT_NAME}>/res/)

# Copies the exe and resources to the install directory when an install is ran
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION .)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/res DESTINATION .)