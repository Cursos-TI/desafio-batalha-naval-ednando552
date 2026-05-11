#include <stdio.h>
int main() {
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; //Letras para as colunas
    int coluna[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //Numero para as linhas
    //Criando o Tabuleiro
    int tabuleiro [10][10]; //Matriz para o tabuleiro
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0; //Inicializa o tabuleiro com 0
        }
    }
    //Navio na horizontal na linha 2, coluna 1 (aqui são os valores da matriz, não do tabuleiro)
    for(int j = 1; j<=3; j++) {
        tabuleiro[2][j] = 3;
    }
    //Navio na vertical na linha 5, coluna 4 (aqui são os valores da matriz, não do tabuleiro)
    for(int i = 5; i<=7; i++) {
        tabuleiro[i][4] = 3;
    }

    //Navio na diagonal principal (aqui a linha aumenta e a coluna também aumenta)
    int diagonal1_linha = 0, diagonal1_coluna = 6; //marca a posição inicial
    for(int i = 0; i <3; i++) {
        int l = diagonal1_linha + i; //Calcula a linha atual
        int c = diagonal1_coluna + i; //Calcula a coluna atual
        if (l < 10 && c < 10 && tabuleiro[l][c] == 0) { //Limite do tabuleiro
            tabuleiro[l][c] = 3; //Coloca o navio na posição
        }
    }
    //Navio na diagonal secundária (linha aumenta, coluna vai diminuir)
    int diagonal2_linha = 5, diagonal2_coluna = 9; //marca a posição inicial
    for(int i = 0; i <3; i++) {
        int l = diagonal2_linha + i; //Calcula a linha atual
        int c = diagonal2_coluna - i; //Calcula a coluna atual
        if (l < 10 && c >= 0 && tabuleiro[l][c] == 0) { //Limite do tabuleiro
            tabuleiro[l][c] = 3; //Coloca o navio na posição
        }
    }
    printf(" Tabuleiro Batalha Naval\n");
    printf ("  ");
    for (int j = 0; j <10; j++) {
        printf("%c ", linha[j]); //Mostra as colunas
    }
    printf("\n");
    for(int i = 0; i < 10; i++) {
        printf("%d ", coluna[i]); //Mostra as linhas
        for (int j = 0; j < 10; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("0 "); //Representa a água
            } else if (tabuleiro[i][j] == 3) {
                printf("3 "); //Representa o navio
            }
        }
        printf("\n");
    }
    return 0;
}