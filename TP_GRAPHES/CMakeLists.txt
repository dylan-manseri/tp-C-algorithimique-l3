cmake_minimum_required(VERSION 4.0)
project(TD1_2 C)

set(CMAKE_C_STANDARD 23)

add_executable(TD1_2 main.c
        structure.h
        partieTP/tab_mat.c
        partieTP/fichiers.c)
