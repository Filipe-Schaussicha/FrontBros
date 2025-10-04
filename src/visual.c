#include "commun.h"
#include "raylib.h"
#include <stdio.h>

void iniciar_fundo(GameOpt *opcoes){

    DrawRectangle(0, SH * 9/10, SW, SH / 10, BLACK);

}

void carregar_jogador(Rectangle jogador, GameOpt *opcoes){

    //printf("Rec: %f %f %f %f\n", jogador.x, jogador.y, jogador.width, jogador.height);

    DrawRectangleRec(jogador, RED);

}