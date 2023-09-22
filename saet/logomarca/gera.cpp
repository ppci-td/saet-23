#include <bits/stdc++.h>

using namespace std;

int main() {

    srand(time(NULL) + clock());

    int r = rand()%50+1;
    int x1, x2;
    do {
        x1 = rand()%(2*r+1) - r;
        x2 = rand()%(2*r+1) - r;
    } while (x1 >= x2);
    printf("%d %d %d\n", r, x1, x2);


    return 0;
}
