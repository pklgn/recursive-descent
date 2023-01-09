set(TEST_PROJECT_TARGET tests)

configure_file(common_dirs_defines.h.in ${CMAKE_CURRENT_BINARY_DIR}/common_dirs_defines.h)

project(${TEST_PROJECT_TARGET}
	LANGUAGES CXX
)

add_executable(${TEST_PROJECT_TARGET}
	${CMAKE_CURRENT_BINARY_DIR}/common_dirs_defines.h
	pch.h
	pch.cpp

	test.parser.cpp
)

target_include_directories(
	${TEST_PROJECT_TARGET}
PRIVATE
	${CMAKE_CURRENT_BINARY_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}

	${PROJECT_LIBRARY_SRC_DIR}
)

target_link_libraries(
	${TEST_PROJECT_TARGET}
PRIVATE
	${PROJECT_LIBRARY_TARGET}
	Catch2::Catch2WithMain
)

catch_discover_tests(${TEST_PROJECT_TARGET})
