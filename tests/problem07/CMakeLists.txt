if(BUILD_TESTING)
get_filename_component(DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(EXENAME ${DIR_NAME}_test)
add_executable(${EXENAME} test.cpp ${PROJECT_SOURCE_DIR}/src/${DIR_NAME}/problem.cpp)
target_include_directories(${EXENAME} PUBLIC ${PROJECT_SOURCE_DIR}/src/${DIR_NAME}/)

target_include_directories(${EXENAME} PRIVATE ${PROJECT_SOURCE_DIR}/src/lib)
target_link_directories(${EXENAME} PRIVATE ${PROJECT_BINARY_DIR}/src/lib)
target_link_libraries(${EXENAME} gtest_main numeric)

include(GoogleTest)
gtest_discover_tests(${EXENAME})
endif()

