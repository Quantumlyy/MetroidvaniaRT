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

set(METROIDVANIART_SHADERS
  src/resources/shaders/BasicFragmentShader.glsl
  src/resources/shaders/BasicVertexShader.glsl
  src/resources/shaders/FontFragmentShader.glsl
  src/resources/shaders/FontVertexShader.glsl
  src/resources/shaders/TexturedFragmentShader.glsl
  src/resources/shaders/TexturedVertexShader.glsl
)

set(METROIDVANIART_FONTS
  src/resources/fonts/Raleway-Regular.ttf
)

set(METROIDVANIART_RESOURCES
  ${METROIDVANIART_SHADERS}
  ${METROIDVANIART_FONTS}
)

file(COPY ${METROIDVANIART_RESOURCES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

find_package(Doxygen QUIET)

set(METROIDVANIART_HEADERS
  include/MetroidvaniaRT.h
  src/lib/MetroidvaniaRunner.h
  src/lib/MetroidvaniaStageService.h
  src/lib/structures/platform/MetroidvaniaPlatform.h
  src/lib/structures/platform/MetroidvaniaImagePlatform.h
  src/lib/structures/platform/MetroidvaniaFillPlatform.h
  src/lib/structures/stage/MetroidvaniaStage.h
)

set(METROIDVANIART_SOURCES
	src/lib/MetroidvaniaRunner.cpp
  src/lib/MetroidvaniaStageService.cpp
  src/lib/structures/platform/MetroidvaniaPlatform.cpp
  src/lib/structures/platform/MetroidvaniaImagePlatform.cpp
  src/lib/structures/platform/MetroidvaniaFillPlatform.cpp
  src/lib/structures/stage/MetroidvaniaStage.cpp
)

set(METROIDVANIART_C_HEADERS
  src/lib_C/MetroidvaniaRunner_C.h
  src/lib_C/MetroidvaniaStageService_C.h
)

set(METROIDVANIART_C_SOURCES
  src/lib_C/MetroidvaniaRunner_C.cpp
  src/lib_C/MetroidvaniaStageService_C.cpp
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
  ${METROIDVANIART_C_HEADERS}
)

set(METROIDVANIART_LIBRARY_SOURCES
  ${METROIDVANIART_SOURCES}
  ${METROIDVANIART_C_SOURCES}
)

set(METROIDVANIART_LIBRARY_LINK_LIBRARIES
  ${METROIDVANIART_LINK_LIBRARIES}
)

add_library(MetroidvaniaRTLib SHARED ${METROIDVANIART_LIBRARY_HEADERS} ${METROIDVANIART_LIBRARY_SOURCES})
target_link_libraries(MetroidvaniaRTLib ${METROIDVANIART_LIBRARY_LINK_LIBRARIES})

if (DOXYGEN_FOUND)
  set(DOXYGEN_METROIDVANIART_INPUT_DIR ${PROJECT_SOURCE_DIR}/src/lib)
  set(DOXYGEN_METROIDVANIART_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/docs)
  set(DOXYGEN_METROIDVANIART_INDEX_FILE ${DOXYGEN_METROIDVANIART_OUTPUT_DIR}/html/index.html)
  set(DOXYGEN_METROIDVANIART_FAKE_INDEX_FILE ${DOXYGEN_METROIDVANIART_OUTPUT_DIR}/html/__index.html)
  set(DOXYFILE_METROIDVANIART_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
  set(DOXYFILE_METROIDVANIART_OUT ${DOXYGEN_METROIDVANIART_OUTPUT_DIR}/Doxyfile)

  set(DOCS_METROIDVANIART_IMAGES
  )
  set(DOCS_METROIDVANIART_RESOURCES
    ${DOCS_METROIDVANIART_IMAGES}
  )

  #Replace variables inside @@ with the current values
  configure_file(${DOXYFILE_METROIDVANIART_IN} ${DOXYFILE_METROIDVANIART_OUT} @ONLY)
  file(MAKE_DIRECTORY ${DOXYGEN_METROIDVANIART_OUTPUT_DIR}) #Doxygen won't create this for us
  file(COPY ${DOCS_METROIDVANIART_RESOURCES} DESTINATION ${DOXYGEN_METROIDVANIART_OUTPUT_DIR})

  add_custom_command(OUTPUT
                       ${DOXYGEN_METROIDVANIART_INDEX_FILE}
                       ${DOXYGEN_METROIDVANIART_FAKE_INDEX_FILE}
                     COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE_METROIDVANIART_OUT}
                     MAIN_DEPENDENCY ${DOXYFILE_METROIDVANIART_OUT} ${DOXYFILE_METROIDVANIART_IN}
                     COMMENT "Generating docs")

  add_custom_target(MetroidvaniaRTDoxygen ALL DEPENDS ${DOXYGEN_METROIDVANIART_INDEX_FILE})
endif (DOXYGEN_FOUND)
