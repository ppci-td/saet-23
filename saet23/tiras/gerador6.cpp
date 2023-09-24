// Gera potencias de 2, alternando as menores com as maiores
#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> bin;
    int c = 100000;

    for(int i = 1; 1<<i <= c; ++i) {
        bin.push_back(1<<i);
    }

    int n = bin.size();

    printf("%d\n", n);
    printf("%d", bin[0]);
    for(int i = 1; i<bin.size(); ++i) {
        if(i&1)
            printf(" %d", bin[n-i]);
        else
            printf(" %d", bin[i]);
    }
    printf("\n");
    fflush(stdout);

    return 0;
}
