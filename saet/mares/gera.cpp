#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main() {

    srand(time(NULL) + clock());
    int tt = 100;
    printf("100\n");
    while (tt--) {
/*        int ndigs = rand()%15 + 1;
        int d;
        for (int i=0;i<ndigs;i++) {
            int d;
            if (i==0) d = rand()%9 + 1;
            else d = rand()%10;
            printf("%d",d);
        }
        printf("\n");*/

        ll n = 1000000000000000ll - rand()%1000;
        printf("%lld\n", n);
    }

    return 0;
}
