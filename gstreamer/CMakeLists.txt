cmake_minimum_required(VERSION 3.0)
project(gstreamer)

find_package(PkgConfig REQUIRED)
find_package(GTK REQUIRED)

pkg_check_modules(GSTREAMER REQUIRED gstreamer-1.0)
pkg_check_modules(GSTREAMER_AUDIO REQUIRED gstreamer-audio-1.0)
pkg_check_modules(GSTREAMER_PBUTILS REQUIRED gstreamer-pbutils-1.0)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

set(BASIC_PATH "${PROJECT_SOURCE_DIR}/basic/")
set(PLAYBACK_PATH "${PROJECT_SOURCE_DIR}/playback/")

include_directories(${GTK3_INCLUDE_DIRS}
                    ${GSTREAMER_INCLUDE_DIRS}
                    ${GSTREAMER_AUDIO_INCLUDE_DIRS}
                    ${GSTREAMER_PBUTILS_INCLUDE_DIRS})

link_directories(${GTK3_LIBRARY_DIRS}
                 ${GSTREAMER_LIBRARY_DIRS}
                 ${GSTREAMER_AUDIO_LIBRARY_DIRS}
                 ${GSTREAMER_PBUTILS_LIBRARY_DIRS})

set(BASIC_TUTORIAL_SOURCES tutorial_1.c tutorial_2.c tutorial_3.c 
                        tutorial_4.c tutorial_5.c tutorial_6.c 
                        tutorial_7.c tutorial_8.c tutorial_9.c 
                        tutorial_10.c tutorial_11.c)

set(PLAYBACK_TUTORIAL_SOURCES tutorial_1.c tutorial_2.c tutorial_3.c
                        tutorial_4.c tutorial_5.c tutorial_6.c
                        tutorial_7.c)


foreach(TUTORIAL_SOURCE ${BASIC_TUTORIAL_SOURCES})
    get_filename_component(TUTORIAL_NAME ${TUTORIAL_SOURCE} NAME_WE)
    add_executable(basic_${TUTORIAL_NAME} ${BASIC_PATH}/${TUTORIAL_SOURCE})
    target_link_libraries(basic_${TUTORIAL_NAME} ${GSTREAMER_LIBRARIES} ${GTK3_LIBRARIES} 
                                ${GSTREAMER_AUDIO_LIBRARIES} ${GSTREAMER_PBUTILS_LIBRARIES})
endforeach()

foreach(TUTORIAL_SOURCE ${PLAYBACK_TUTORIAL_SOURCES})
    get_filename_component(TUTORIAL_NAME ${TUTORIAL_SOURCE} NAME_WE)
    add_executable(playback_${TUTORIAL_NAME} ${PLAYBACK_PATH}/${TUTORIAL_SOURCE})
    target_link_libraries(playback_${TUTORIAL_NAME} ${GSTREAMER_LIBRARIES} ${GTK3_LIBRARIES} 
                                ${GSTREAMER_AUDIO_LIBRARIES} ${GSTREAMER_PBUTILS_LIBRARIES})
endforeach()

add_executable(test_rtsp test/test_rtsp.c)
target_link_libraries(test_rtsp ${GSTREAMER_LIBRARIES} ${GTK3_LIBRARIES} 
                        ${GSTREAMER_AUDIO_LIBRARIES} ${GSTREAMER_PBUTILS_LIBRARIES})

add_executable(device2udp test/device2udp.c)
target_link_libraries(device2udp ${GSTREAMER_LIBRARIES} ${GTK3_LIBRARIES} 
                        ${GSTREAMER_AUDIO_LIBRARIES} ${GSTREAMER_PBUTILS_LIBRARIES})