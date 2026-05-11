#include <stdio.h>
#include <stdlib.h>

int main() {
    char linha[10] = {'A','B','C','D','E','F','G','H','I','J'};
    int coluna[10] = {1,2,3,4,5,6,7,8,9,10};
    char tabuleiro[10][10];

    // Inicializa tabuleiro com água
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            tabuleiro[i][j] = '~';
        }
    }

    //Navios nas horizontais e verticais
    tabuleiro[1][2] = 'N';
    tabuleiro[1][3] = 'N';
    tabuleiro[1][4] = 'N';

    tabuleiro[5][5] = 'N';
    tabuleiro[6][5] = 'N';
    tabuleiro[7][5] = 'N';

    //Navios diagonais
    //Diagonal principal (linha+1, coluna+1)
    tabuleiro[2][6] = 'N';
    tabuleiro[3][7] = 'N';
    tabuleiro[4][8] = 'N';

    //Diagonal secundária (linha+1, coluna-1)
    tabuleiro[5][9] = 'N';
    tabuleiro[6][8] = 'N';
    tabuleiro[7][7] = 'N';

    //MATRIZES DE HABILIDADES 5x5
    int tamanho = 5;
    int cone[5][5] = {0};
    int cruz[5][5] = {0};
    int octaedro[5][5] = {0};

    //Cone
    cone[0][2] = 1;
    cone[1][1] = cone[1][2] = cone[1][3] = 1;
    cone[2][0] = cone[2][1] = cone[2][2] = cone[2][3] = cone[2][4] = 1;

    //Cruz
    cruz[0][2] = 1;
    cruz[1][0] = cruz[1][1] = cruz[1][2] = cruz[1][3] = cruz[1][4] = 1;
    cruz[2][2] = 1;

    //Octaedro
    octaedro[0][2] = 1;
    octaedro[1][1] = octaedro[1][2] = octaedro[1][3] = 1;
    octaedro[2][2] = 1;

    //SOBREPOSIÇÃO DAS HABILIDADES
    int origem_cone_l = 0, origem_cone_c = 7;
    int origem_cruz_l = 4, origem_cruz_c = 2;
    int origem_octa_l = 6, origem_octa_c = 7;

    for(int i=0;i<tamanho;i++){
        for(int j=0;j<tamanho;j++){
            int l, c;

            //Cone
            l = origem_cone_l + i;
            c = origem_cone_c - 2 + j;
            if(l>=0 && l<10 && c>=0 && c<10 && cone[i][j]==1){
                if(tabuleiro[l][c]=='~') tabuleiro[l][c]='h';
            }

            //Cruz
            l = origem_cruz_l + i;
            c = origem_cruz_c - 2 + j;
            if(l>=0 && l<10 && c>=0 && c<10 && cruz[i][j]==1){
                if(tabuleiro[l][c]=='~') tabuleiro[l][c]='h';
            }

            //Octaedro
            l = origem_octa_l - 2 + i;
            c = origem_octa_c - 2 + j;
            if(l>=0 && l<10 && c>=0 && c<10 && octaedro[i][j]==1){
                if(tabuleiro[l][c]=='~') tabuleiro[l][c]='h';
            }
        }
    }

    //EXIBIÇÃO DO TABULEIRO
    printf("***Tabuleiro Batalha Naval***\n");
    printf("  ");
    for(int j=0;j<10;j++) printf("%c ", linha[j]);
    printf("\n");

    for(int i=0;i<10;i++){
        printf("%d ", coluna[i]);
        for(int j=0;j<10;j++){
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}