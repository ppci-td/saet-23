#include <bits/stdc++.h>

using namespace std;

int nasc[100010];

int main(int argc, char *argv[]) {

    srand(time(NULL) + clock());

    if (argc != 2) {
        printf("%s n\n", argv[0]);
        return 0;
    }
    int n;
    sscanf(argv[1], "%d", &n);

    printf("%d\n", n);
    n++;
    // gera n aleatorios pra ser os nascimentos
    for (int i=0;i<n;i++) nasc[i] = i;
    for (int i=0;i<n;i++) {
        int tt = rand()%(n-i);
        swap(nasc[i], nasc[i+tt]);
    }

    for (int i=1;i<n;i++) {
        int pai = rand()%i;
        printf("%d %d\n", pai, nasc[i]);

    }

    return 0;
}
