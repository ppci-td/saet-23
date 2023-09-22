#include <bits/stdc++.h>

using namespace std;

set<int> S;

int main() {

    srand(time(NULL) + clock());

    int n = 100000, m = 100000-1;
    printf("%d %d\n", n, m);
    for (int i=0;i<m;i++) {
        if (i) printf(" ");
        printf("%d",n-i);
    }
    printf("\n");









    /*int n = 100000-rand()%100, m = 100000-rand()%100;
    printf("%d %d\n", n, m);
    for (int i=0;i<n;i++)
        S.insert(i);
    for (int i=0;i<m;i++) {
        if (i) printf(" ");
        int r = rand()%100;
        if (S.size()==1 or r<=20) { // 20 % de pau
            printf("0");
        } else {
            int t;
            do {
                t = rand()%n;
            } while (S.find(t) == S.end());
            S.erase(t);
            printf("%d",t+1);
        }
    }*/
    return 0;
}
