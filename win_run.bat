setlocal enabledelayedexpansion

:: Caminho para o emscripten
set caminho_emsdk=..\..\emsdk\upstream\emscripten\emcc.bat

:: Nome do arquivo de saida
set nome=frontBros

:: Lê todos os arquivos .c na pasta src
set "arquivos="

for %%f in (src\*.c) do (
    set "arquivos=!arquivos! %%f"
)

:: Imprimi o terminal, os arquivos selecionados
echo "arquivos a compilar: !arquivos!"

:: Para while(!WindowSholdClose())
:: Adicionar "-s ASYNCIFY" no final

:: Chama o comando para compilar
call %caminho_emsdk% !arquivos! raylib\lib\libraylib.a -o %nome%.html -Os -Wall -Iinclude -Iraylib\include -s USE_GLFW=3 -DPLATFORM_WEB

echo "Compilação pronta!"