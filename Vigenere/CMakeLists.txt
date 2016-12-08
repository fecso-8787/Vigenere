cmake_minimum_required (VERSION 3.6)
set(TARGET_NAME Vigenere)
project(${TARGET_NAME})

add_definitions(-DWINDOWS_LEAN_AND_MEAN)

#include_directories("src")
#include_directories("include")

file(GLOB_RECURSE HEADERS
    "include/*.h"
)
file(GLOB_RECURSE SOURCES
        "src/*.cpp"
)

file(GLOB_RECURSE RESOURCES
        "Resource/*.dat"
)

add_executable(${TARGET_NAME} WIN32 ${HEADERS} ${SOURCES} ${RESOURCES})

set_target_properties(${TARGET_NAME} PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:CONSOLE")

source_group("Headers"            FILES ${HEADERS})
source_group("Sources"        FILES ${SOURCES})
source_group("Resource"        FILES ${RESOURCES})

# copy resource dat executable
  add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
    COMMAND "${CMAKE_COMMAND}" -E copy_directory
    "${CMAKE_SOURCE_DIR}/${TARGET_NAME}/Resource"
    $<TARGET_FILE_DIR:${TARGET_NAME}>/Resource
  )