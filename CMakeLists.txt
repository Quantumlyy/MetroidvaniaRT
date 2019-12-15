cmake_minimum_required(VERSION 3.13)

project(MetroidvaniaRT VERSION 0.0.1)
include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VS_PLATFORM_TOOLSET_HOST_ARCHITECTURE "x64")

# Registering dependencies
add_subdirectory(dependencies/NovelRT)

if (WIN32)
  set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

set(METROIDVANIART_HEADERS
  src/lib/MetroidvaniaRunner.h
  src/lib/structures/Character.h
)

set(METROIDVANIART_SOURCES
	src/lib/MetroidvaniaRunner.cpp
  src/lib/structures/Character.cpp
)

set(METROIDVANIART_LINK_LIBRARIES
  NovelRTLib
)

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
