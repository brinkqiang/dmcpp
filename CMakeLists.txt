cmake_minimum_required(VERSION 3.2)

PROJECT(dmcpp)

cmake_policy(SET CMP0026 OLD)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
INCLUDE(cmake/ModuleImport.cmake)
INCLUDE(cmake/ModuleCompileOptions.cmake)
INCLUDE(cmake/UseBackportedModules.cmake)
ModuleSetCompileOptions()

IF(MSVC)
    include(CreateLaunchers)
ENDIF()

ModuleImport("dmlog" "thirdparty/dmlog")
ModuleImport("dmtest" "thirdparty/dmtest")
LibImport("dmcpp" "src")
ExeImport("test" "dmcpp;dmtest")

IF(MSVC)
    create_target_launcher(dmfiletest WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")
ENDIF()
