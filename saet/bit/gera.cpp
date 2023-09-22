#include <bits/stdc++.h>

using namespace std;

// [0]  [2]
// |     |
// v     v
// [1]->[3]

int main() {

    srand(time(NULL) + clock());
    int n = 2000;
    int m = 1999;
    printf("%d %d\n", n, m);
    for (int i=0;i<n;i+=2) {
        int a = i;
        int b = i+1;
        printf("%d %d\n", a+1, b+1);
    }
    for (int i=1;i+2<n;i+=2)
        printf("%d %d\n", i+1, i+3);

    return 0;
}
