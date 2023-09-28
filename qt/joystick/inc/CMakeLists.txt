find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Quick)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick)
file(GLOB_RECURSE MYLIBS ./*.h ./*.hpp)

add_library(mylibs STATIC  ${MYLIBS} )

target_link_libraries(mylibs  Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick )