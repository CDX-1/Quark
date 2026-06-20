cmake_minimum_required(VERSION 3.19)
project(Quark VERSION 1.0.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_definitions(NOMINMAX)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

set(CEF_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/third_party/cef")
list(APPEND CMAKE_MODULE_PATH "${CEF_ROOT}/cmake")
find_package(CEF REQUIRED)

add_subdirectory("${CEF_ROOT}/libcef_dll" libcef_dll_wrapper)

set(QUARK_SOURCES
    src/main.cpp
    src/quark_app.cpp
    src/quark_client.cpp
)

add_executable(Quark WIN32 ${QUARK_SOURCES})
target_include_directories(Quark PRIVATE "${CEF_ROOT}")

target_link_libraries(Quark PRIVATE 
    libcef_dll_wrapper 
    debug "${CEF_ROOT}/Debug/libcef.lib"
    optimized "${CEF_ROOT}/Release/libcef.lib"
    ${CEF_STANDARD_LIBS}
)

add_custom_command(TARGET Quark POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CEF_ROOT}/Debug/"
        "$<TARGET_FILE_DIR:Quark>"
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CEF_ROOT}/Resources/"
        "$<TARGET_FILE_DIR:Quark>"
    COMMENT "Copying CEF runtime files and resources next to the executable..."
)