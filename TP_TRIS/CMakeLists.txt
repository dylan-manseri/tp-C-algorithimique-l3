cmake_minimum_required(VERSION 3.23)
project(TP1 C)

# Tous les exécutables dans cmake-build-xxx/out
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)

add_executable(triInser triInser.c)
add_executable(triSel   triSel.c)
add_executable(triFusion triFusion.c)