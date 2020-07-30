cmake_minimum_required(VERSION 3.2)

PROJECT(dmcpp)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
INCLUDE(cmake/ModuleImport.cmake)
INCLUDE(cmake/ModuleCompileOptions.cmake)
ModuleSetCompileOptions()

SET(DMCPP_VERSION_MAJOR "1")
SET(DMCPP_VERSION_MINOR "0")
SET(DMCPP_VERSION_PATCH "1")
SET(DMCPP_VERSION "${DMCPP_VERSION_MAJOR}.${DMCPP_VERSION_MINOR}.${DMCPP_VERSION_PATCH}")

MESSAGE(STATUS "VERSION: ${DMCPP_VERSION}")

OPTION(USE_DMCPP "use dmcpp" OFF)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/include/dmcpp_config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/include/dmcpp_config.h)

ModuleImport("dmlog" "thirdparty/dmlog")
LibImport("dmcpp" "src")
ExeImport("test" "dmcpp")
