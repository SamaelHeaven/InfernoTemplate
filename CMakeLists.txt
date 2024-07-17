cmake_minimum_required(VERSION 3.5.0)
project(game)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static -static-libgcc -static-libstdc++")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(inferno QUIET)
if (NOT inferno_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            inferno
            DOWNLOAD_EXTRACT_TIMESTAMP OFF
            URL https://github.com/SamaelHeaven/Inferno/archive/refs/heads/master.zip
    )
    FetchContent_GetProperties(inferno)
    if (NOT inferno_POPULATED)
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(inferno)
        add_subdirectory(${inferno_SOURCE_DIR} ${inferno_BINARY_DIR})
    endif ()
endif ()

add_executable(${PROJECT_NAME}
        src/game.cpp
        src/game.h
        src/scenes/MainScene.cpp
        src/scenes/MainScene.h
)

target_link_libraries(${PROJECT_NAME} PUBLIC inferno)

if (${PLATFORM} STREQUAL "Desktop")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3 -s -mwindows")
endif ()

if (EMSCRIPTEN)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY -s GL_ENABLE_GET_PROC_ADDRESS=1")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --preload-file ${PROJECT_SOURCE_DIR}/resources@/resources")
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
else ()
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${PROJECT_SOURCE_DIR}/resources $<TARGET_FILE_DIR:${PROJECT_NAME}>/resources
    )
endif ()

if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif ()