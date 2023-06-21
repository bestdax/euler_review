get_filename_component(DIRNAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(EXENAME ${DIRNAME})
add_executable(${EXENAME} main.cpp problem.cpp)
