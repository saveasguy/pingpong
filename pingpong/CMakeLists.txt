find_package(Curses REQUIRED)

message("${NCURSES_INCLUDE_DIR}")

add_executable(pingpong
    src/main.cpp
)
target_include_directories(pingpong PRIVATE ${CURSES_INCLUDE_DIR})
target_link_libraries(pingpong PRIVATE ${CURSES_LIBRARIES})
