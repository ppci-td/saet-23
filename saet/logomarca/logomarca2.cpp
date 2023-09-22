#include <bits/stdc++.h>

#define PASSOS 10000000

using namespace std;

int main() {

    double r, x1, x2;
    scanf("%lf %lf %lf", &r, &x1, &x2);
    double resp = r*r*asin(x2/r) + x2*sqrt(r*r - x2*x2)
                 -r*r*asin(x1/r) - x1*sqrt(r*r - x1*x1);
    printf("%.3lf\n", resp);

    return 0;
}
