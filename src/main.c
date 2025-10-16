/* 
    Exemplo de código web:
    https://github.com/raysan5/raylib/blob/d97e0a8ac7ac150585e697344bf625e1583fe91c/examples/core/core_basic_window_web.c
*/

#include "commun.h"
#include <math.h>
#include <stdio.h>
#include "raylib.h"
#include <emscripten/emscripten.h>
#include "menu.h"

GameOpt opcoes = {MENU, 0};

static RenderTexture2D target;

void desenharFrame(){

    // calcula escala para manter 16:9 dentro do canvas atual
    float screenW = (float)GetScreenWidth();
    float screenH = (float)GetScreenHeight();

    float scale = fminf(screenW / (float)VW, screenH / (float)VH);

    int scaledW = (int)(VW * scale);
    int scaledH = (int)(VH * scale);
    int offsetX = (int)((screenW - scaledW) / 2.0f);
    int offsetY = (int)((screenH - scaledH) / 2.0f);

    //---------------------------------------------------------------------

    BeginTextureMode(target);
        ClearBackground(RAYWHITE);


        switch(opcoes.tela){
            case MENU:
            menu(&opcoes);
            break;
        
        }

        // ... restante do seu draw ...
    EndTextureMode();

    //---------------------------------------------------------------------

    BeginDrawing();
    ClearBackground(BLACK);

    // desenha a render texture escalada e centralizada
    DrawTexturePro(
        target.texture,
        (Rectangle){ 0.0f, 0.0f, (float)target.texture.width, -(float)target.texture.height }, // origem (invertendo Y)
        (Rectangle){ (float)offsetX, (float)offsetY, (float)scaledW, (float)scaledH },      // destino
        (Vector2){ 0.0f, 0.0f },
        0.0f,
        WHITE
    );
    
    
    EndDrawing();
}


int main() {
    
    InitWindow(1280, 720, "FrontEnd Bros.");
    SetTargetFPS(60);

    target = LoadRenderTexture(VW, VH);
    SetTextureFilter(target.texture, TEXTURE_FILTER_BILINEAR);

    emscripten_set_main_loop(desenharFrame, 0, 1);

    UnloadRenderTexture(target);
    CloseWindow();
    return 0;
}

