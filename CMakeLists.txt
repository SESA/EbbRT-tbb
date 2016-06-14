cmake_minimum_required(VERSION 2.6)

# This must be before the project() command so cmake finds our platform
# definition
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../cmake")

# This skips compiler verification which will fail because we haven't finished
# installing the necessary libraries
set(CMAKE_CXX_COMPILER_WORKS 1)

project(Tbb CXX)

# Initialize CXXFLAGS.
set(CMAKE_CXX_FLAGS                "-Wall -Werror -std=gnu++14 -iquote ${CMAKE_SOURCE_DIR}/include")
set(CMAKE_CXX_FLAGS_DEBUG          "-O0 -g3")
set(CMAKE_CXX_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE        "-O4 -flto -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g3")

add_library(tbb STATIC
  ${CMAKE_SOURCE_DIR}/spin_rw_mutex.cpp
  ${CMAKE_SOURCE_DIR}/tbb_misc.cpp
  )

install(TARGETS tbb
  ARCHIVE DESTINATION lib)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/tbb DESTINATION include
  FILES_MATCHING PATTERN "*.h")
