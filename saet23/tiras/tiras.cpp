// Algoritmo guloso. Leva em consideracao que:
// * GCD eh uma operacao com propriedade associativa;
// * Apos todas as operacoes, sempre irah resultar em um vetor com 
//   valores igual ao GCD entre todos os numeros.

#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) { return b==0 ? a : gcd(b,a%b); }

int n, v[100000];

int main() {
    scanf("%d", &n);

    for(int i = 0; i<n; ++i) {
        scanf("%d", &v[i]);
    }

    int g = v[0];
    for(int i = 1; i<n; ++i) {
        g = gcd(g, v[i]);
    }

    int saida = 0;
    for(int i = 0; i<n-1; ++i) {
        if(v[i] != g) {
            v[i+1] = gcd(v[i], v[i+1]);
            ++saida;
        }
    }
    if(v[n-1] != g) 
        saida++;

    printf("%d\n", saida);

    return 0;
}
