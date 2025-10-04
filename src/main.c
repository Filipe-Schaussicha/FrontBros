/* 
    Exemplo de código web:
    https://github.com/raysan5/raylib/blob/d97e0a8ac7ac150585e697344bf625e1583fe91c/examples/core/core_basic_window_web.c
*/

#include "raylib.h"
#include <emscripten/emscripten.h>
#include "commun.h"
#include "jogo.h"

void desenharFrame();

GameOpt opcoes = {FASE_1, MURILO};

int main() {
    
    InitWindow(SW, SH, "FrontEnd Bros.");
    SetTargetFPS(60);

    emscripten_set_main_loop(desenharFrame, 0, 1);

    CloseWindow();
    return 0;
}

void desenharFrame(){

    BeginDrawing();
    ClearBackground(RAYWHITE);

    switch(opcoes.tela){

        case FASE_1:
            fase_1(&opcoes);
            break;
        
    }
    
    EndDrawing();
}
