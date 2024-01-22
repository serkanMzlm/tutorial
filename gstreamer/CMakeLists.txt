cmake_minimum_required(VERSION 3.0)
project(gstreamer)

find_package(PkgConfig REQUIRED)
find_package(GTK REQUIRED)

pkg_check_modules(GSTREAMER REQUIRED gstreamer-1.0)
pkg_check_modules(GSTREAMER_AUDIO REQUIRED gstreamer-audio-1.0)
pkg_check_modules(GSTREAMER_PBUTILS REQUIRED gstreamer-pbutils-1.0)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

set(FILE_PATH "${PROJECT_SOURCE_DIR}/src/")

include_directories(${GSTREAMER_INCLUDE_DIRS})
include_directories(${GTK3_INCLUDE_DIRS} ${GSTREAMER_INCLUDE_DIRS})
include_directories(${GSTREAMER_INCLUDE_DIRS} ${GSTREAMER_AUDIO_INCLUDE_DIRS})
include_directories(${GSTREAMER_INCLUDE_DIRS} ${GSTREAMER_PBUTILS_INCLUDE_DIRS})

link_directories(${GTK3_LIBRARY_DIRS} ${GSTREAMER_LIBRARY_DIRS})
link_directories(${GSTREAMER_LIBRARY_DIRS} ${GSTREAMER_AUDIO_LIBRARY_DIRS})
link_directories(${GSTREAMER_LIBRARY_DIRS} ${GSTREAMER_PBUTILS_LIBRARY_DIRS})

add_executable(basic_tutorial_1 ${FILE_PATH}/basic_tutorial_1.c)
target_link_libraries(basic_tutorial_1  ${GSTREAMER_LIBRARIES})

add_executable(basic_tutorial_2 ${FILE_PATH}/basic_tutorial_2.c)
target_link_libraries(basic_tutorial_2  ${GSTREAMER_LIBRARIES})

add_executable(basic_tutorial_3 ${FILE_PATH}/basic_tutorial_3.c)
target_link_libraries(basic_tutorial_3  ${GSTREAMER_LIBRARIES})

add_executable(basic_tutorial_4 ${FILE_PATH}/basic_tutorial_4.c)
target_link_libraries(basic_tutorial_4  ${GSTREAMER_LIBRARIES})

add_executable(basic_tutorial_5 ${FILE_PATH}/basic_tutorial_5.c)
target_link_libraries(basic_tutorial_5  ${GSTREAMER_LIBRARIES} ${GTK3_LIBRARIES})

add_executable(basic_tutorial_6 ${FILE_PATH}/basic_tutorial_6.c)
target_link_libraries(basic_tutorial_6  ${GSTREAMER_LIBRARIES})

add_executable(basic_tutorial_7 ${FILE_PATH}/basic_tutorial_7.c)
target_link_libraries(basic_tutorial_7  ${GSTREAMER_LIBRARIES})

add_executable(basic_tutorial_8 ${FILE_PATH}/basic_tutorial_8.c)
target_link_libraries(basic_tutorial_8  ${GSTREAMER_LIBRARIES} ${GSTREAMER_AUDIO_LIBRARIES})

add_executable(basic_tutorial_9 ${FILE_PATH}/basic_tutorial_9.c)
target_link_libraries(basic_tutorial_9  ${GSTREAMER_LIBRARIES} ${GSTREAMER_PBUTILS_LIBRARIES})

# add_executable(basic_tutorial_10 ${FILE_PATH}/basic_tutorial_10.c)
# target_link_libraries(basic_tutorial_10  ${GSTREAMER_LIBRARIES})

# add_executable(basic_tutorial_11 ${FILE_PATH}/basic_tutorial_11.c)
# target_link_libraries(basic_tutorial_11  ${GSTREAMER_LIBRARIES})

# add_executable(basic_tutorial_12 ${FILE_PATH}/basic_tutorial_12.c)
# target_link_libraries(basic_tutorial_12  ${GSTREAMER_LIBRARIES})