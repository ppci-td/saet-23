#include <bits/stdc++.h>

using namespace std;

int n;
int v[128];

int main() {

    scanf("%d", &n);
    int soma=0;
    for (int i=0;i<n;i++) {
        scanf("%d", v+i);
        soma += v[i];
    }
    if (soma&1) {
        printf("NAO\n");
        return 0;
    }
    printf("SIM\n");

    return 0;
}
