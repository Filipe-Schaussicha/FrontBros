
#define SW 1280
#define SH 720

#define NULO = -1

// Telas do jogo
enum{
    MENU,
    MAPA,
    FASE_1,
    FASE_2,
    FASE_3,
    OPT,
    GAMEOVER
};

// Personagem selecionados
enum{
    MURILO
};

typedef struct{
    
    int tela;
    int jogador;

}GameOpt;