cmake_minimum_required(VERSION 3.0)
project(gstreamer)

find_package(PkgConfig REQUIRED)

pkg_check_modules(GSTREAMER REQUIRED gstreamer-1.0)
pkg_check_modules(GSTREAMER_AUDIO REQUIRED gstreamer-audio-1.0)
pkg_check_modules(GSTREAMER_PBUTILS REQUIRED gstreamer-pbutils-1.0)

include_directories(${GSTREAMER_INCLUDE_DIRS}
                    ${GSTREAMER_AUDIO_INCLUDE_DIRS}
                    ${GSTREAMER_PBUTILS_INCLUDE_DIRS})

link_directories(${GSTREAMER_LIBRARY_DIRS}
                 ${GSTREAMER_AUDIO_LIBRARY_DIRS}
                 ${GSTREAMER_PBUTILS_LIBRARY_DIRS})

add_executable(test_rtsp test_rtsp.c)
target_link_libraries(test_rtsp ${GSTREAMER_LIBRARIES} ${GSTREAMER_AUDIO_LIBRARIES} 
                                                        ${GSTREAMER_PBUTILS_LIBRARIES})

add_executable(test_rtsp_2 test_rtsp_2.c)
target_link_libraries(test_rtsp_2 ${GSTREAMER_LIBRARIES} ${GSTREAMER_AUDIO_LIBRARIES} 
                                                        ${GSTREAMER_PBUTILS_LIBRARIES})