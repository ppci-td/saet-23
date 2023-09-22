#include <bits/stdc++.h>

using namespace std;

int v[100010];

int main() {

    srand(time(NULL) + clock());
    int n = 100000 - rand()%1000;
    int m = 100 - rand()%10;

    printf("%d %d\n", n, m);
    for (int i=0;i<n;i++) {
        if (i) printf(" ");
        int r = rand()%5;
        if (r==0)
            printf("B");
        else if (r==1)
            printf("N");
        else
            printf("%d", rand()%m + 1);
    }
    printf("\n");

    return 0;
}
