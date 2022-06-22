add_executable(
        exe
        executable.c
)

target_link_libraries(
        exe
        stack
)

target_compile_options(
        exe
        BEFORE
        PUBLIC
        -Wall
        -Wextra
        -Wpedantic
        -Wformat
        -Wvla
        -Wfloat-equal
        -Werror
)
