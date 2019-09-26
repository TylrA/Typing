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

target_compile_features (optimizer PRIVATE c_std_99)
target_compile_features (unit PRIVATE c_std_99)

target_compile_options (optimizer PRIVATE -Wall -Wextra)
target_compile_options (unit PRIVATE -Wall -Wextra)

target_link_libraries (optimizer m pthread)
target_link_libraries (unit m pthread)

set (CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0 -fno-inline")
set (CMAKE_C_FLAGS_PROFILE "-g -pg -O2 -fno-inline")
set (CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG")


