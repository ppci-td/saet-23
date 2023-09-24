// Gera 1 100000 1 100000 1 100000 ...
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 100000;
    int c0 = 1;
    int c1 = 100000;

    printf("%d\n", n);

    printf("%d", c0);
    for(int i = 1; i<n; ++i) {
        if(i&1)
            printf(" %d", c1);
        else
            printf(" %d", c0);

    }
    printf("\n");

    return 0;
}
