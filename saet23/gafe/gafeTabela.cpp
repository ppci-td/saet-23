/*  
    Gera todas as respostas e coloca em um CSV. 
    Usei isso para pegar alguns casos de teste, olhando na tabela.
    A primeira linha e primeira coluna são os valores de E e D.
*/

#include <bits/stdc++.h>

using namespace std;

int E, D;
int mem[1001][1001];

int solve(int e, int d) {
    if (mem[e][d] != -1) return mem[e][d];

    if (e == 0) return d;
    if (d == 0) return e;

    int decE = solve(e-1, d);
    int decD = solve(e, d-1);
    int sub  = e >= d ? solve(e-d, d) : solve(e, d-e);

    return mem[e][d] = 1 + min({decE, decD, sub});
}

int main() {
    memset(mem, 0xff, sizeof(mem)); // Inicializa com -1

    for(int i = 0; i<=1000; ++i) {
        printf(",%d", i);
    }
    printf("\n");
    for(int i = 0; i<=1000; ++i) {
        printf("%d", i);
        for(int j = 0; j<=1000; ++j) {
            printf(",%d", solve(i, j));
        }
        printf("\n");
    }

    return 0;
}
