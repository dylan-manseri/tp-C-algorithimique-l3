cmake_minimum_required(VERSION 4.0)
project(LISTE_DOUBLE C)

set(CMAKE_C_STANDARD 23)

add_executable(LISTE_DOUBLE1
        exercice1/main.c
        exercice1/structure.h
        exercice1/fonctionListeDC.c
        exercice1/exercice1.c
)

add_executable(LISTE_DOUBLE2
        exercice2/main.c
        exercice2/fonctionListeDCTQ.c
        exercice2/exercice2.c
)
