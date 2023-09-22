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
    int qro = soma/2;
    sort(v,v+n);
    bool ok=false;

    int i, j, vez=0, tot=0;
    i = 0, j = n-1;
    while (i <= j) {
        if (vez == 0)
            tot += v[i++];
        else
            tot += v[j--];
        vez ^= 1;
        if (tot == qro) {
            ok = true;
            break;
        }
    }

    vez=1;
    i = 0, j = n-1;
    tot = 0;
    while (i <= j) {
        if (vez == 0)
            tot += v[i++];
        else
            tot += v[j--];
        vez ^= 1;
        if (tot == qro) {
            ok = true;
            break;
        }
    }

    printf("%s\n", ok ? "SIM" : "NAO");

    return 0;
}
