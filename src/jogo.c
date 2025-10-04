#include "commun.h"
#include "raylib.h"
#include "visual.h"

void fase_1(GameOpt *opcoes){

    Rectangle chao = {0, SH * 9/10, SW, SH / 10};
    Rectangle jogador = {SW / 10, SH * 8/10, SW / 20, SH /10};

    iniciar_fundo(opcoes);

    //movimenta_jogador(&jogador);

    carregar_jogador(jogador, opcoes);

}