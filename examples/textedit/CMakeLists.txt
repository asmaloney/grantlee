project(textedit_grantlee)

cmake_minimum_required(VERSION 3.0)

find_package(Grantlee5 REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

## Grantlee plugin

add_library(customtags MODULE
  customtagslibrary.cpp
  audiotextdocumentoutputter.cpp
  filters.cpp
)
grantlee_adjust_plugin_name(customtags)

target_link_libraries(customtags
  ${Grantlee_TEMPLATES_LIBRARIES}
  ${Grantlee_TEXTDOCUMENT_LIBRARIES}
)


## Application

get_property(Grantlee_PLUGIN_DIR TARGET Grantlee5::defaulttags PROPERTY LOCATION)
get_filename_component(Grantlee_PLUGIN_DIR ${Grantlee_PLUGIN_DIR} PATH)
get_filename_component(Grantlee_PLUGIN_DIR ${Grantlee_PLUGIN_DIR} PATH)
get_filename_component(Grantlee_PLUGIN_DIR ${Grantlee_PLUGIN_DIR} PATH)

configure_file(grantlee_paths.h.cmake ${PROJECT_BINARY_DIR}/grantlee_paths.h)


add_executable(textedit
  main.cpp
  audiotextedit.cpp
  audioobject.cpp
  textedit.cpp
  textedit.qrc
)

target_link_libraries(
  textedit
  Qt4::QtWebKit
  Qt4::phonon
  ${Grantlee_TEMPLATES_LIBRARIES}
)
