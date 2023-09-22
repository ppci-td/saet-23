#include <bits/stdc++.h>

using namespace std;

int n, m;
typedef pair<int, int> ii;
ii v[100010];

int main() {

    scanf("%d %d", &n, &m);
    for (int i=0;i<n;i++)
        v[i] = ii(i,i);
    while (m--) {
        int a;
        scanf("%d", &a); a--;
        if (a == -1) {
            int ult = v[n-1].second;
            for (int i=n-1;i>0;i--)
                v[i].second = v[i-1].second;
            v[0].second = ult;
        } else {
            int r=-1;
            for (int i=0;i<n;i++)
                if (v[i].first == a)
                    r=i;
            assert(r!=-1);
            for (int i=r;i+1<n;i++)
                v[i] = v[i+1];
            n--;
        }
    }
    for (int i=0;i<n;i++)
        printf("%d %d\n", v[i].first+1, v[i].second+1);

    return 0;
}
