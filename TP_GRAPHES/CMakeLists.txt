cmake_minimum_required(VERSION 3.31.6)

project(TD_GRAPHES C)

set(CMAKE_C_STANDARD 23)

add_executable(TD_GRAPHES main.c
        include/structure.h
        TD1_2/partieTP/alloc_lib.c
        TD1_2/partieTP/fichiers.c
        TD1_2/partieTD/exo3.c
        utils/fonctionsListe.c
        TD1_2/partieTD/exo4.c
        utils/print.c
        TD3/exo4.c
        include/prototypeTD12.h
        include/prototypeTD3.h
        TD1_2/mainTD1_2.c
        main.c
        TD3/mainTD3.c
)
