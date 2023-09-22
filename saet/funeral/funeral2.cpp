#include <bits/stdc++.h>

#define SIZE 100010
#define EPS 1e-12

using namespace std;

int n;
long double a[SIZE];
long double x[SIZE];
long double v[SIZE];
long double t[SIZE];

inline int cmpf(long double a, long double b) {
    if (fabs(a-b) < EPS) return 0;
    return a < b ? -1 : 1;
}

int main() {

    scanf("%d %Lf", &n, &a[0]);
    x[0] = 0;
    v[0] = 0;
    t[0] = 0;
    for (int i=1;i<n;i++)
        scanf("%Lf %Lf", x+i, a+i);
    scanf("%Lf", x+n);

    for (int i=1;i<=n;i++) {
        // entre x[i-1] e x[i]
        long double v2 = v[i-1]*v[i-1] + 2.0*a[i-1]*(x[i]-x[i-1]);
        assert(cmpf(v2,0.0)>0);
        v[i] = sqrt( v2 );
        if (cmpf(a[i-1],0.0)==0)
            t[i] = t[i-1] + (x[i]-x[i-1])/v[i-1];
        else
            t[i] = t[i-1] + (v[i]-v[i-1])/a[i-1];
        //printf("cheguei em x_%d em %.2Lf s e v = %.2Lf m/s\n", i, t[i], v[i]);
    }
    printf("%.2Lf\n", t[n]);

    return 0;
}
