#include <bits/stdc++.h>

using namespace std;

int n;
int v[128];

int main() {

    scanf("%d", &n);
    int soma=0;
    for (int i=0;i<n;i++) {
        scanf("%d",v+i);
        soma += v[i];
    }
    if (soma&1) { printf("NAO\n"); return 0; }
    int qro = soma/2;
    sort(v,v+n);
    int atu=0;
    bool da=false;
    for (int i=0;i<n;i++) {
        atu += v[i];
        if (v[i]==qro) {
            da=true;
            break;
        }
        if (atu > qro) break;
    }

    printf("%s\n", da ? "SIM" : "NAO" );

    return 0;
}
