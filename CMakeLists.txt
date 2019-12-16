cmake_minimum_required(VERSION 3.13)

project(MetroidvaniaRT VERSION 0.0.1)
include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VS_PLATFORM_TOOLSET_HOST_ARCHITECTURE "x64")

# Ensure dependencies are placed in the main output directory
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Registering dependencies
add_subdirectory(dependencies/NovelRT)

set(METROIDVANIART_HEADERS
  src/lib/MetroidvaniaRunner.h
  src/lib/structures/platform/MetroidvaniaPlatform.h
  src/lib/structures/platform/MetroidvaniaImagePlatform.h
  src/lib/structures/platform/MetroidvaniaFillPlatform.h
  src/lib/structures/stage/MetroidvaniaStage.h
)

set(METROIDVANIART_SOURCES
	src/lib/MetroidvaniaRunner.cpp
  src/lib/structures/platform/MetroidvaniaPlatform.cpp
  src/lib/structures/platform/MetroidvaniaImagePlatform.cpp
  src/lib/structures/stage/MetroidvaniaStage.cpp
)

set(METROIDVANIART_LINK_LIBRARIES
  NovelRTLib
)

set(METROIDVANIART_EXECUTABLE_HEADERS
  ${METROIDVANIART_HEADERS}
)

set(METROIDVANIART_EXECUTABLE_SOURCES
  src/main.cpp
)

set(METROIDVANIART_EXECUTABLE_LINK_LIBRARIES
  ${METROIDVANIART_LINK_LIBRARIES}
  MetroidvaniaRTLib
)

add_executable(MetroidvaniaRT ${METROIDVANIART_EXECUTABLE_HEADERS} ${METROIDVANIART_EXECUTABLE_SOURCES})
target_link_libraries(MetroidvaniaRT ${METROIDVANIART_EXECUTABLE_LINK_LIBRARIES})

if (WIN32)
  set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

set(METROIDVANIART_LIBRARY_HEADERS
  ${METROIDVANIART_HEADERS}
)

set(METROIDVANIART_LIBRARY_SOURCES
  ${METROIDVANIART_SOURCES}
)

set(METROIDVANIART_LIBRARY_LINK_LIBRARIES
  ${METROIDVANIART_LINK_LIBRARIES}
)

add_library(MetroidvaniaRTLib SHARED ${METROIDVANIART_LIBRARY_HEADERS} ${METROIDVANIART_LIBRARY_SOURCES})
target_link_libraries(MetroidvaniaRTLib ${METROIDVANIART_LIBRARY_LINK_LIBRARIES})
