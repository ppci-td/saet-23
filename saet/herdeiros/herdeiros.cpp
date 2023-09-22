#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> adj[100010];
int pai[100010];
int nasc[100010];

bool cmp(int a, int b) {
    return nasc[a] < nasc[b];
}

int main() {

    scanf("%d", &n);
    n++;
    for (int i=0;i<n;i++) adj[i].clear();
    for (int i=1;i<n;i++) {
        scanf("%d %d", pai+i, nasc+i);
        adj[pai[i]].push_back(i);
    }
    for (int i=0;i<n;i++)
        sort(adj[i].begin(), adj[i].end(), cmp);

    queue<int> Q;
    Q.push(0);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        if (u!=0) printf("%d\n", u);
        for (int i=0;i<(int)adj[u].size();i++)
            Q.push(adj[u][i]);
    }

    return 0;
}
