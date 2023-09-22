#include <bits/stdc++.h>

using namespace std;

int n, m, tambl, nbl;
int BIT[100010];
list<int> L[320];

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
    memset(BIT,0,sizeof(BIT));
    for (int i=1;i<=n;i++)
        update(i,+1);

    tambl = (int)sqrt(n);
    tambl = max(tambl,1);
    nbl = (n+tambl-1)/tambl;
    for (int i=0;i<nbl;i++) {
        int a = i*tambl + 1;
        int b = a+tambl - 1;
        if (b > n) b=n;

        for (int j=a;j<=b;j++)
            L[i].push_back(j);
    }

    while (m--) {
        int a;
        scanf("%d", &a);
        if (a==0) {
            // roda
            for (int i=0;i<nbl;i++) {
                int tt = L[i].back();
                L[i].pop_back();
                L[(i+1)%nbl].push_front(tt);
            }
        } else {
            // tira equipe
            int qual = query(a);
            update(a, -1);

            int bloco = 0, soma=0;
            while (soma < qual) {
                soma += (int)L[bloco].size();
                bloco++;
            }
            bloco--;
            soma -= L[bloco].size();
            list<int>::iterator Li = L[bloco].begin();
            while (soma < qual) {
                Li++;
                soma++;
            }
            Li--;
            L[bloco].erase(Li);
        }
    }

    vector<int> times, pcs;
    for (int i=1;i<=n;i++)
        if (query(i)-query(i-1) == 1)
            times.push_back(i);
    for (int i=0;i<nbl;i++)
        for (list<int>::iterator Li = L[i].begin();Li != L[i].end(); Li++)
            pcs.push_back(*Li);

    for (int i=0;i<(int)times.size();i++)
        printf("%d %d\n", times[i], pcs[i]);


    return 0;
}
