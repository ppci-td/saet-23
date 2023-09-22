#include <bits/stdc++.h>

using namespace std;

int n, m, tambl, nbl;
int BIT[100010];
list<int> L;
bool desistiu[100010];

void update(int u, int x) {
    for (int i = u; i <= n; i += i & -i)
        BIT[i] += x;
}

int query(int u) {
    int res = 0;
    for (int i = u; i; i -= i & -i)
        res += BIT[i];
    return res;
}

int main() {

    scanf("%d %d", &n, &m);
    memset(BIT,0,(n+3)*sizeof(int));
    memset(desistiu,false,(n+3)*sizeof(bool));
    for (int i=1;i<=n;i++) {
        update(i,+1);
        L.push_back(i);
    }

    while (m--) {
        int a;
        scanf("%d", &a);
        if (a==0) {
            // roda (em O(1) )
            int tt = L.back();
            L.pop_back();
            L.push_front(tt);
        } else {
            // tira equipe (em O(N))
            desistiu[a] = true;
            int qual = query(a);
            update(a, -1);

            list<int>::iterator Li = L.begin();
            for (int i=0;i<qual;i++)
                Li++;
            Li--;
            L.erase(Li);
        }
    }

    int t = 1;
    for (list<int>::iterator Li = L.begin();Li != L.end(); Li++) {
        while (desistiu[t]) t++;
        printf("%d %d\n", t++, *Li);
    }

    return 0;
}
