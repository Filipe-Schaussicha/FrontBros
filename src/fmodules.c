#include "raylib.h"
#include <math.h>

// Calcula o x em que o texto deve ser desenhado para ficar centralizado
float centro_x_texto(char *texto, int centro, int tamanho_fonte, Font fonte){

    Vector2 largura_texto = MeasureTextEx(fonte, texto, tamanho_fonte, 2);
    return centro - largura_texto.x / 2;

}

// Cria um botão e verifica se foi clicado
bool btn(Rectangle retangulo, float margin, char *texto, Color externo, Color interno, Color texto_cor){

    Font fonte = GetFontDefault();

    float diferenca;
    bool clicado = false;
    Vector2 mouse = GetMousePosition();

    // Verifica se o mouse está acima do botão
    if(CheckCollisionPointRec(mouse, retangulo)){

        diferenca = retangulo.height * sin(GetTime() * 2) * 0.1;

        retangulo.x -= diferenca / 2;
        retangulo.y -= diferenca / 2;
        retangulo.height += diferenca;
        retangulo.width += diferenca;

        // Verifica se o mouse clicou no notão
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            clicado = true;
        }

    }

    // Desenha o botão
    DrawRectangleRec(retangulo, externo);

    diferenca = retangulo.height * margin;

    retangulo.x += diferenca / 2;
    retangulo.y += diferenca / 2;
    retangulo.height -= diferenca;
    retangulo.width -= diferenca;

    DrawRectangleRec(retangulo, interno);

    diferenca = retangulo.height * margin;

    retangulo.x += diferenca / 2;
    retangulo.y += diferenca ;
    retangulo.height -= diferenca;
    retangulo.width -= diferenca;

    // Vefica se o texto não vai ficar maior que o botão
    Vector2 largura = MeasureTextEx(fonte, texto, retangulo.height, 2);
    while(largura.x > retangulo.width){
        retangulo.height--;
        retangulo.y += 0.5;
        largura = MeasureTextEx(fonte, texto, retangulo.height, 2);
    }

    // Desenha o texto
    DrawTextEx(fonte, texto, (Vector2){centro_x_texto(texto, retangulo.x + retangulo.width / 2, retangulo.height, fonte) , retangulo.y}, retangulo.height, 2, texto_cor);

    return clicado;
}

void DrawTextCenter(char *txt, Vector2 pos, int size, Color cor){

    Font fonte = GetFontDefault();

    pos.x = centro_x_texto(txt, pos.x, size, fonte);

    DrawText(txt, pos.x, pos.y, size, cor);
}