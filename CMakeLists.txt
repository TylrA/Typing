cmake_minimum_required (VERSION 3.10)

add_executable (optimizer
  optimizer.c
  accessories.c
  cjalgorithm.c
  fitness.c
  keyboard.c
  tools.c
  values.c)

add_executable (unit
  unit.c
  accessories.c
  cjalgorithm.c
  fitness.c
  keyboard.c
  tools.c
  values.c)

# set to C standard 99
target_compile_features (optimizer PRIVATE c_std_99)
target_compile_features (unit PRIVATE c_std_99)

# add some flags for all build types
target_compile_options (optimizer PRIVATE -Wall -Wextra)
target_compile_options (unit PRIVATE -Wall -Wextra)

# add libraries
target_link_libraries (optimizer m pthread)
target_link_libraries (unit m pthread)

# define build type flags
set (CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0 -fno-inline")
set (CMAKE_C_FLAGS_PROFILE "-g -pg -O2 -fno-inline")
set (CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG")

# copy data files to build
# configure_file (data data)
file (COPY ${PROJECT_SOURCE_DIR}/data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

