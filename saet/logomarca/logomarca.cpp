#include <bits/stdc++.h>

#define PASSOS 1000000

using namespace std;

int main() {

    double r, x1, x2;
    scanf("%lf %lf %lf", &r, &x1, &x2);
    double delta = (x2-x1)/(double)PASSOS;
    double tot = 0;
    for (int i=0;i<PASSOS;i++) {
        double x = x1 + (double)i*delta + delta/2.0;
        double y = sqrt(r*r - x*x);
        tot += y*delta;
    }
    printf("%.3lf\n", 2.0*tot);

    return 0;
}
