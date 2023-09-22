#include <bits/stdc++.h>

using namespace std;


int main() {

    int n;

    scanf("%d", &n);
    if (n>0 and (n%2)==0 and (n%10)!=0)
        printf("sim\n");
    else
        printf("nao\n");

    return 0;
}
