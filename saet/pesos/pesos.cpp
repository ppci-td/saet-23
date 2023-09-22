#include <bits/stdc++.h>

using namespace std;

int n;
int v[128];
int PD[128][10010];

int calc(int u, int obj) {
    int &pd = PD[u][obj];
    if (pd != -1) return pd;
    if (u==n)
        return pd = (obj==0 ? 1 : 0);
    if (calc(u+1, obj)==1)
        return pd = 1;
    if (obj-v[u]>=0 and calc(u+1, obj-v[u])==1)
        return pd=1;
    return pd=0;
}

int main() {

    scanf("%d", &n);
    int soma=0;
    for (int i=0;i<n;i++) {
        scanf("%d",v+i);
        soma += v[i];
    }
    if (soma&1) { printf("NAO\n"); return 0; }
    int qro = soma/2;
    memset(PD,0xff,sizeof(PD));
    int resp = calc(0, qro);
    printf("%s\n", resp==1 ? "SIM" : "NAO" );

    return 0;
}
