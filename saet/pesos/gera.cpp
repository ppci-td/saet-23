#include <bits/stdc++.h>

using namespace std;

int v[128];

int main() {

    srand(time(NULL) + clock());
    int r = rand()%2;
    if (r==0) {
        // SIM

        int qro = rand()%5000 + 1;
        v[0] = qro;
        v[1] = qro;

        int n = rand()%100 + 1;
        if (n > 100) n = 100;
        if (n < 2) n = 2;
        if (n > 2*qro) n = 2*qro;
        for (int i=2;i<n;i++) {
            int tt;
            do {
                tt = rand()%i;
            } while (v[tt] == 1);

            int tot = v[tt];
            int a = rand()%(tot-1) + 1;
            int b = tot - a;
            v[tt] = a;
            v[i] = b;
        }

        printf("%d\n", n);
        for (int i=0;i<n;i++) {
            if (i) printf(" ");
            int tt = rand()%(n-i);
            swap(v[i], v[i+tt]);
            printf("%d",v[i]);
        }
        printf("\n");
    } else {
        // NAO
        int n = rand()%100 + 1;
        printf("%d\n", n);
        for (int i=0;i<n;i++) {
            if (i) printf(" ");
            printf("%d", rand()%100 + 1);
        }
        printf("\n");
    }

    return 0;
}
