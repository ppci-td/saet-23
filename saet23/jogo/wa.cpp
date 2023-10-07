#include <bits/stdc++.h>

using namespace std;

int n;
multiset<int> atacantes, zagueiros;

int main() {
    scanf("%d", &n);

    for(int i = 0; i<n; ++i) {
        int a, d;
        scanf("%d %d", &a, &d);
        if(d>a) {
            zagueiros.insert(a+d);
        }
        else {
            atacantes.insert(a+d);
        }
    }

    n = n/2 * 2;

    set<int> atk[2], def[2]; // Daqui vem o erro!
    int pontos[2] = {};

    int vez = 0;
    for(int i = 0; i<n; ++i) {
        if(i&1) {
            vez ^= 1;
        }

        if(atacantes.size() == 0) {
            def[vez].insert(*prev(zagueiros.end()));
            zagueiros.erase(prev(zagueiros.end()));
            pontos[vez] += *(def[vez].begin());
        }
        else if(zagueiros.size() == 0) {
            atk[vez].insert(*prev(atacantes.end()));
            atacantes.erase(prev(atacantes.end()));
            pontos[vez] += *(atk[vez].begin());
        }
        else if(atk[vez].size() > def[vez].size()){
            def[vez].insert(*prev(zagueiros.end()));
            zagueiros.erase(prev(zagueiros.end()));
            pontos[vez] += *(def[vez].begin());
        }
        else if(atk[vez].size() < def[vez].size()) {
            atk[vez].insert(*prev(atacantes.end()));
            atacantes.erase(prev(atacantes.end()));
            pontos[vez] += *(atk[vez].begin());
        }
        else if(*prev(zagueiros.end()) > *prev(atacantes.end())) {
            def[vez].insert(*prev(zagueiros.end()));
            zagueiros.erase(prev(zagueiros.end()));
            pontos[vez] += *(def[vez].begin());
        }
        else if(*prev(atacantes.end()) >= *prev(zagueiros.end())) {
            atk[vez].insert(*prev(atacantes.end()));
            atacantes.erase(prev(atacantes.end()));
            pontos[vez] += *(atk[vez].begin());
        }
    }
    
    double saida = max((double)pontos[0]/n*2, (double)pontos[1]/n*2);

    printf("%.2lf\n", saida);

    return 0;
}
