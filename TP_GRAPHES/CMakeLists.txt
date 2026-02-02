cmake_minimum_required(VERSION 3.31.6)

project(TD1_2 C)

set(CMAKE_C_STANDARD 23)

add_executable(TD1_2 main.c
        include/structure.h
        partieTP/alloc_lib.c
        partieTP/fichiers.c
        partieTD/exo3.c
        utils/fonctionsListe.c
        partieTD/exo4.c
        utils/print.c
)
