cmake_minimum_required(VERSION 3.24)
project(ai_assignment_3 C)

set(CMAKE_C_STANDARD 11)

add_executable(ai_assignment_3
        main.c
        loadAndDisplay.h loadAndDisplay.c
        menu.h menu.c
        editItemInList.h editItemInList.c
        # Add other source files if needed
)
