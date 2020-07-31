cmake_minimum_required(VERSION 3.2)

PROJECT(dmcpp)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
INCLUDE(cmake/ModuleImport.cmake)
INCLUDE(cmake/ModuleCompileOptions.cmake)
ModuleSetCompileOptions()

ModuleImport("dmlog" "thirdparty/dmlog")
LibImport("dmcpp" "src")
ExeImport("test" "dmcpp")
