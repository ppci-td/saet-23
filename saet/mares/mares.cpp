#include <bits/stdc++.h>

#define ll long long int

using namespace std;

ll PD[24][2];
ll n;
ll s[24];

ll calc(ll u, ll livre) {
    if (PD[u][livre] != -1ll) return PD[u][livre];
    if (u==0) {
        ll c = 0;
        ll lim = (livre ? 9 : s[u]);
        for (ll d=2;d<=lim;d+=2)
            c++;
        return PD[u][livre] = c;
    }
    ll lim = (livre ? 9 : s[u]);
    ll soma = 0;
    for (ll d=1;d<=lim;d++) {
        ll nlivre;
        if (livre or d < s[u]) nlivre = 1;
        else nlivre = 0;
        soma += calc(u-1, nlivre);
    }
    return PD[u][livre] = soma;
}

ll qnts(ll m) {
    ll n = 0;
    while (m) {
        s[n++] = (m%10);
        m /= 10;
    }

    memset(PD,0xff,sizeof(PD));
    ll soma = 0;
    // livre ateh o penultimo digito (zero a esquerda pode)
    for (ll i=0;i<n-1;i++)
        soma += calc(i, 1);
    // n livre no ultimo
    soma += calc(n-1,0);
    return soma;
}

int main() {

    ll tt;
    for(scanf("%lld",&tt);tt--;) {
        scanf("%lld", &n);
        assert(1 <= n and n <= 1000000000000000ll);
        n--;

        //XXX limite do N eh 10^15 p/ fim caber em 10^18
        ll ini = 1, fim = 1000000000000000000ll, r = -1ll;
        while (ini <= fim) {
            ll meio = (ini+fim)/2ll;
            ll q = qnts(meio);
//            printf("%lld mares ate %lld\n", q, meio);
            if (q <= n)
                ini = meio+1;
            else {
                r = meio;
                fim = meio-1;
            }
        }
        printf("%lld\n", r);
    }
    return 0;
}
