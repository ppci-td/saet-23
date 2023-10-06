// Gera entradas com resposta "S". Criei algumas entradas e modifiquei
// manualmente para dar resposta "N".
#include <bits/stdc++.h>

using namespace std;

int main() {
    int N = 100;
    int R[100], A[100];

    srand(time(NULL) + clock());

    printf("%d\n", N);

    for(int i = 0; i<N; ++i) {
        R[i] = rand()%2;

        if(i) {
            printf(" %d", R[i]);
        }
        else {
            printf("%d", R[i]);
        }
    }
    printf("\n");

    for(int i = 0; i<N; ++i) {
        if(R[i]) {
            A[i] = 0;
        }
        else {
            A[i] = rand()%2;
        }

        if(i) {
            printf(" %d", A[i]);
        }
        else {
            printf("%d", A[i]);
        }
    }
    printf("\n");

    return 0;
}
