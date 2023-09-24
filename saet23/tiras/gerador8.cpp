// Gera soh numeros primos aleatorios
#include <bits/stdc++.h>

using namespace std;

#define MAX_C 100000
#define MAX_N 100000

int main() {
    srand(time(NULL) + clock());

    int n = min(MAX_N, 99991);

    vector<int> primo;
    int ehComposto[MAX_C+1] = {};

    for(int i = 2; i*i<=MAX_C; ++i) { // Crivo de Eratóstenes
        if(!ehComposto[i]) {
            for(int j = i<<1; j<=MAX_C; j += i) {
                ehComposto[j] = 1;
            }
        }
    }

    for(int i = 2; i<=MAX_C; ++i)
        if(!ehComposto[i])
            primo.push_back(i);

    printf("%d\n", n);

    printf("%d", min(primo[rand()%primo.size()], MAX_C));
    for(int i = 1; i<n; ++i) {
        printf(" %d", min(primo[rand()%primo.size()], MAX_C));
    }
    printf("\n");

    return 0;
}
