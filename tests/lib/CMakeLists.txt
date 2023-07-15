if(BUILD_TESTING)
  get_filename_component(DIRNAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
  set(TESTEXE ${DIRNAME}_test)

  add_executable(${TESTEXE} test.cpp ${PROJECT_SOURCE_DIR}/${DIRNAME}/sint.cpp)
  target_link_libraries(${TESTEXE} PRIVATE gtest_main sint)

  include(GoogleTest)
  gtest_discover_tests(${TESTEXE})
endif()
