#define VW 1280
#define VH 720

#define NULO = -1

// Telas do jogo
enum{
    MENU,
    JOGO,
    OPT,
    GAMEOVER
};

typedef struct{
    
    int tela;
    int jogador;

}GameOpt;