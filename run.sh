#! /bin/bash

source /home/filipe/Documentos/Programas/emsdk/emsdk_env.sh

echo "Emsdk pronto!"

emcc src/*.c \
    raylib/lib/libraylib.a \
    -o frontBros.html \
    -Os -Wall \
    -Iinclude \
    -Iraylib/include \
    -s USE_GLFW=3 \
    -DPLATFORM_WEB \
    #-s ASYNCIFY 

echo "Compilação pronta!"

python3 -m http.server 8080
