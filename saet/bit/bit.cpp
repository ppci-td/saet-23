#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[2020];
bool vis[2020];
bool entra[2020];

int dfs(int u) {
    vis[u] = true;
    int r = 1;
    for (auto w : adj[u]) if (!vis[w])
        r += dfs(w);
    return r;
}

int main() {

    scanf("%d %d", &n, &m);
    memset(entra,false,sizeof(entra));
    for (int i=0;i<m;i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        adj[a].push_back(b);
        entra[b]= true;
    }
    int maior = 0, r = -1;
    for (int i=0;i<n;i++) if (!entra[i]) {
        memset(vis,false,sizeof(vis));
        int tt = dfs(i);
        if (tt > maior) {
            maior = tt;
            r = i;
        }
    }
    printf("%d %d\n", r+1, maior-1);

    return 0;
}
