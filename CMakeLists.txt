cmake_minimum_required (VERSION 3.6)
project(VigenereProj)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMakeTargets")

add_definitions(-DNOMINMAX -D_CRT_SECURE_NO_WARNINGS)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zi")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /DEBUG /OPT:REF /OPT:ICF")
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${WINDOW_SDK_PATH})

# Hide automoc folders (for IDEs)
set(AUTOGEN_TARGETS_FOLDER "hidden/generated")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_subdirectory(Vigenere)