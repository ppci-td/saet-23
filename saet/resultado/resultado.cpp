#include <bits/stdc++.h>

using namespace std;

struct cmp {
    bool operator()(int a, int b) {
        return a > b;
    }
};

int votos[100010];
int n, m;
char aux[32];
multiset<int, cmp> S;

int main() {

    memset(votos,0,sizeof(votos));
    scanf("%d %d", &n, &m);
    int validos=0;
    for (int i=0;i<n;i++) {
        scanf("%s", aux);
        if (aux[0]=='B' or aux[0]=='N') continue;
        validos++;
        int c;
        sscanf(aux,"%d", &c);
        votos[c]++;
    }

    int maior = -1, winner=-1, segundo=-1, smaior=-1, qntsmaior=0;
    for (int i=1;i<=m;i++)
        if (votos[i] > maior) {
            segundo=winner;
            smaior = maior;
            maior = votos[i];
            winner=i;
        } else if (votos[i] > smaior) {
            smaior = votos[i];
            segundo = i;
        }

    for (int i=1;i<=m;i++)
        if (votos[i] == maior)
            qntsmaior++;
    assert(qntsmaior==1);
    if (2*maior > validos) {
        printf("vencedor %d\n", winner);
        return 0;
    } else {
        for (int i=1;i<=m;i++) if (votos[i] > 0)
            S.insert(votos[i]);
        assert( S.size() >= 2 );
        multiset<int, cmp>::iterator Si = S.begin();
        int a = *Si;
        Si++;
        int b = *Si;
        Si++;
        if (S.size()==2)
            assert(a != b);
        else {
            int c = *Si;
            Si++;
            assert(a != b and a != c and b != c);
        }

        printf("segundo turno entre %d e %d\n", winner, segundo);
    }

    return 0;
}
