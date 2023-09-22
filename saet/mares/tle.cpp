#include <bits/stdc++.h>

#define ll long long int

using namespace std;

ll n;

inline bool temzero(ll r) {
    while (r) {
        if ((r%10ll)==0) return true;
        r /= 10ll;
    }
    return false;
}

int main() {

    int tt;
    for(scanf("%d",&tt);tt--;) {
        scanf("%lld", &n);
        assert(1 <= n and n <= 1000000000000000ll);
        ll atu = 2;
        ll i = 1;
        while (i < n) {
            do { atu += 2; } while (temzero(atu));
            i++;
        }

        printf("%lld\n", atu);
    }
    return 0;
}
