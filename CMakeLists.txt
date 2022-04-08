cmake_minimum_required(VERSION 3.10)

file(GLOB SOURCES *.h *.cpp )
get_filename_component(full_path_test_cpp ${CMAKE_CURRENT_SOURCE_DIR}/test.cpp ABSOLUTE)
list(REMOVE_ITEM SOURCES "${full_path_test_cpp}")
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_library(patchmatch_inpaint SHARED ${SOURCES})
target_link_libraries(patchmatch_inpaint ${OpenCV_LIBRARIES})