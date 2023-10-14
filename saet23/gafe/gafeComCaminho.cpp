/*  
    Apenas para ver o caminho de uma das soluções possíveis.
    Cada linha imprime os níveis dos dois lados no momento, e 
    a escolha que foi feita:

    * Se for E, então decrementou da esquerda;
    * Se for D, então decrementou da direita;
    * Se for S, então subtraiu do lado maior a lado menor.

*/

#include <bits/stdc++.h>

using namespace std;

int E, D;
int mat[1001][1001];
char pai[1001][1001];

void printarCaminho(int e, int d) { 
    if(e != 0 or d != 0) {
        printf(" %4d %4d  ->  %c\n", e, d, pai[e][d]);

        if (pai[e][d] == 'E')
            printarCaminho(e-1, d);
        else if (pai[e][d] == 'D')
            printarCaminho(e, d-1);
        else if (e >= d)
            printarCaminho(e-d, d);
        else
            printarCaminho(e, d-e);
    }
    else {
        printf(" %4d %4d  ->  FIM\n", e, d);
    }
}

int main() {
    scanf("%d %d", &E, &D);

    mat[0][0] = 0;

    for(int i = 0; i<=1000; ++i) {
        mat[i][0] = mat[0][i] = i;
        pai[i][0] = 'E';
        pai[0][i] = 'D';
    }
    pai[0][0] = 'X';

    for(int i = 1; i<=E; ++i) {
        for(int j = 1; j<=D; ++j) {
            int decE = mat[i-1][j];
            int decD = mat[i][j-1];

            int sub;
            if(i >= j) {
                sub = mat[i-j][j];
            } else {
                sub = mat[i][j-i];
            }

            if (decE <= decD and decE <= sub) {
                mat[i][j] = decE+1;
                pai[i][j] = 'E';
            }
            else if (decD < decE and decD <= sub) {
                mat[i][j] = decD+1;
                pai[i][j] = 'D';
            }
            else {
                mat[i][j] = sub+1;
                pai[i][j] = 'S';
            }
        }
    }

    printf("Melhor caso: %d\n", mat[E][D]);
    printf("Caminho achado:\n");
    printarCaminho(E, D);

    return 0;
}
