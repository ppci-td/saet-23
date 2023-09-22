#include <bits/stdc++.h>

#define SIZE 100010
#define EPS 1e-8

using namespace std;

int n, X[SIZE], A[SIZE];
double a[SIZE];
double x[SIZE];
double v[SIZE];
set<int> S;

inline int cmpf(double a, double b) {
    if (fabs(a-b) < EPS) return 0;
    return a < b ? -1 : 1;
}

int main() {

    srand(time(NULL) + clock());

comeco:;
    //int n = 10000 - rand()%1000;
    int n = 100 - rand()%10;
    A[0] = rand()%100;

    a[0] = (double)A[0];
    x[0] = 0;
    v[0] = 0;

    // gera n inteiros distintos
    S.clear();
    for (int i=0;i<n;i++) {
        int t;
        do {
            t = rand()%1000;
        } while (S.find(t) != S.end());
        S.insert(t);
        X[i] = t;
    }
    sort(X,X+n);

    for (int i=1;i<n;i++) {
        x[i] = (double)X[i-1];
        if (rand()%4 == 0)
            A[i] = 0;
        else
            A[i] = (rand()%201 - 100);
        a[i] = (double)A[i];
    }
    x[n] = (double)X[n-1];

    for (int i=1;i<=n;i++) {
        double v2 = v[i-1]*v[i-1] + 2.0*a[i-1]*(x[i]-x[i-1]);
        if (cmpf(v2,0.0) <= 0) {
            //printf("> v2 = %.2lf\n", v2);
            goto comeco;
        }
        v[i] = sqrt( v2 );
        //printf("+ %.2lf\n", v[i]);
    }

    printf("%d %d\n", n, A[0]);
    for (int i=1;i<n;i++)
        printf("%d %d\n", X[i-1], A[i]);
    printf("%d\n", X[n-1]);

    return 0;
}
