#include <bits/stdc++.h>

#define MAX 1000

using namespace std;

int va[1024], vb[1024];

int main() {

    srand(time(NULL) + clock());

    int n = MAX - rand()%10;
    printf("%d\n", n);
    int r = rand()%3;
    if (r==0) {
        // full rand
        int na = MAX-rand()%10;
        printf("%d\n", na);
        for (int i=0;i<na;i++) {
            if (i) printf(" ");
            printf("%d", rand()%n + 1);
        }
        printf("\n");
        int nb = MAX-rand()%10;
        printf("%d\n", nb);
        for (int i=0;i<nb;i++) {
            if (i) printf(" ");
            printf("%d", rand()%n + 1);
        }
        printf("\n");
    } else if (r==1) {
        // ok
        for (int i=0;i<n;i++) {
            va[i]=i+1;
            vb[i]=i+1;
        }
        int trocas = rand()%(n/2) + 1;
        while (trocas--) {
            int ra = rand()%n;
            int rb = rand()%n;
            swap(va[ra], vb[rb]);
        }
        // copias extras
        int na = n + rand()%(n/10);
        na = min(na, MAX);
        for (int i=n;i<na;i++)
            va[i] = va[rand()%n];
        int nb = n + rand()%(n/10);
        nb = min(nb, MAX);
        for (int i=n;i<nb;i++)
            vb[i] = vb[rand()%n];
        // shuffle e printa
        printf("%d\n", na);
        for (int i=0;i<na;i++) {
            int tt = rand()%(na-i);
            swap(va[i],va[i+tt]);
            if (i) printf(" ");
            printf("%d",va[i]);
        }
        printf("\n");
        printf("%d\n", nb);
        for (int i=0;i<nb;i++) {
            int tt = rand()%(nb-i);
            swap(vb[i],vb[i+tt]);
            if (i) printf(" ");
            printf("%d",vb[i]);
        }
        printf("\n");
    } else {
        // quase ok
        for (int i=0;i<n;i++) {
            va[i]=i+1;
            vb[i]=i+1;
        }
        int trocas = rand()%(n/2) + 1;
        while (trocas--) {
            int ra = rand()%n;
            int rb = rand()%n;
            swap(va[ra], vb[rb]);
        }
        // copias extras [pode ser qlqr um]
        int na = n + rand()%(n/10);
        na = min(na, MAX);
        for (int i=n;i<na;i++)
            va[i] = rand()%n + 1;
        int nb = n + rand()%(n/10);
        nb = min(nb, MAX);
        for (int i=n;i<nb;i++)
            vb[i] = rand()%n + 1;
        // shuffle e printa
        printf("%d\n", na);
        for (int i=0;i<na;i++) {
            int tt = rand()%(na-i);
            swap(va[i],va[i+tt]);
            if (i) printf(" ");
            printf("%d",va[i]);
        }
        printf("\n");
        printf("%d\n", nb);
        for (int i=0;i<nb;i++) {
            int tt = rand()%(nb-i);
            swap(vb[i],vb[i+tt]);
            if (i) printf(" ");
            printf("%d",vb[i]);
        }
        printf("\n");
    }

    return 0;
}
