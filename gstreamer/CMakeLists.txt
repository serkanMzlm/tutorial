cmake_minimum_required(VERSION 3.0)
project(gstreamer)

find_package(PkgConfig REQUIRED)
find_package(GTK REQUIRED)

pkg_check_modules(GSTREAMER REQUIRED gstreamer-1.0)
pkg_check_modules(GSTREAMER_AUDIO REQUIRED gstreamer-audio-1.0)
pkg_check_modules(GSTREAMER_PBUTILS REQUIRED gstreamer-pbutils-1.0)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

set(BASIC_PATH "${PROJECT_SOURCE_DIR}/basic/")

include_directories(${GTK3_INCLUDE_DIRS}
                    ${GSTREAMER_INCLUDE_DIRS}
                    ${GSTREAMER_AUDIO_INCLUDE_DIRS}
                    ${GSTREAMER_PBUTILS_INCLUDE_DIRS})

link_directories(${GTK3_LIBRARY_DIRS}
                 ${GSTREAMER_LIBRARY_DIRS}
                 ${GSTREAMER_AUDIO_LIBRARY_DIRS}
                 ${GSTREAMER_PBUTILS_LIBRARY_DIRS})

set(TUTORIAL_SOURCES tutorial_1.c tutorial_2.c tutorial_3.c 
                        tutorial_4.c tutorial_5.c tutorial_6.c 
                        tutorial_7.c tutorial_8.c tutorial_9.c 
                        tutorial_10.c tutorial_11.c)

foreach(TUTORIAL_SOURCE ${TUTORIAL_SOURCES})
    get_filename_component(TUTORIAL_NAME ${TUTORIAL_SOURCE} NAME_WE)
    add_executable(basic_${TUTORIAL_NAME} ${BASIC_PATH}/${TUTORIAL_SOURCE})
    target_link_libraries(basic_${TUTORIAL_NAME} ${GSTREAMER_LIBRARIES} ${GTK3_LIBRARIES} 
                                ${GSTREAMER_AUDIO_LIBRARIES} ${GSTREAMER_PBUTILS_LIBRARIES})
endforeach()