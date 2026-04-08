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
        TD4/partieTP.c
        TD4/mainTD4.c
        include/prototypeTD4.h
        utils/fonctionStruct.c
        include/prototypeTD5.h
        TD5/partieTP.c
        TD5/mainTD5.c
        include/prototypeTD6.h
        TD6/partieTP.c
        TD6/mainTD6.c
        TD7/partieTP.c
        TD7/mainTD7.c
        include/prototypeTD7.h
        include/prototypeTD8.h
        TD8/partieTP.c
        TD9/partieTP.c
        include/prototypeTD9.h
)
