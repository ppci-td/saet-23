#include <bits/stdc++.h>

#define M 1000000000

using namespace std;

int main() {

    srand(time(NULL) + clock());

    int r = rand()%4;
    int n;
    if (r==0) {
        // negativo
        n = -(rand()%M);
    } else if (r==1) {
        // termina com 0
        n = rand()%M;
        n = n/10;
        n = n*10;
    } else {
        // qlqr coisa
        n = rand()%M;
    }
    printf("%d\n", n);


    return 0;
}
