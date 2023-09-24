// Gera soh numeros multiplos de g = 1012
#include <bits/stdc++.h>

using namespace std;

#define MAX_C 100000
#define MAX_N 100000

int main() {
    srand(time(NULL) + clock());

    int n = MAX_N;

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

    int g = 2*2*11*23; // Escolhi o MDC igual a isso, que resulta em 1012.
    int max_idx_primo = upper_bound(primo.begin(), primo.end(), MAX_C/g) - primo.begin();

    printf("%d\n", n);

    printf("%d", min(g*primo[rand()%max_idx_primo], MAX_C));
    for(int i = 1; i<n; ++i) {
        printf(" %d", min(g*primo[rand()%max_idx_primo], MAX_C));
    }
    printf("\n");

    return 0;
}
