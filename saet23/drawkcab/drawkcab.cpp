#include <bits/stdc++.h>

#define SIZE 500050

using namespace std;

typedef pair<int, int> ii;
typedef struct {
    int maxpfsum, soma;
    int ini, fim;
    int esq, dir;
} nodo;

nodo M[2*SIZE];
int pQ=0;

char s[SIZE];
int  v[SIZE], valor[32];
int  R[SIZE];
int n;

int constroi(int ini, int fim) {
    int r = pQ++;
    M[r].ini = ini; M[r].fim = fim;
    M[r].esq = M[r].dir = -1;
    if (ini==fim) {
        M[r].soma = M[r].maxpfsum = v[ini];
        return r;
    }
    int meio = (ini+fim)/2;
    M[r].esq = constroi(ini,meio);
    M[r].dir = constroi(meio+1,fim);
    M[r].soma = M[ M[r].esq ].soma + M[ M[r].dir ].soma;
    M[r].maxpfsum = max( M[ M[r].esq ].maxpfsum, M[ M[r].esq ].soma + M[ M[r].dir ].maxpfsum);
    return r;
}

// retorna (maxpfsum, soma)
ii query(int r, int ini, int fim) {
    if (ini > M[r].fim or fim < M[r].ini) return ii(-0x3f3f3f3f, 0);
    if (ini <= M[r].ini and M[r].fim <= fim)
        return ii(M[r].maxpfsum, M[r].soma);
    ii resq = query(M[r].esq, ini, fim);
    ii rdir = query(M[r].dir, ini, fim);

    ii ret;
    ret.second = resq.second + rdir.second;
    ret.first = max( resq.first, resq.second + rdir.first);
    return ret;
}

// versao Par (R[i] = raio pal. centro entre i e i+1)
void manacherP() {
    int i,j,k;
    for (i=j=0;i<n;i+=k) {
        for (; i-j >= 0 and i+j+1 < n and s[i-j] == s[i+j+1]; j++);
        R[i]=j;
        for (k=1;i-k >= 0 and k<=R[i] and R[i-k] != R[i]-k; k++) {
            R[i+k] = min(R[i-k],R[i]-k);
        }
        j = max(0,j-k);
    }
}

// versao Impar (R[i] = raio pal. centro em i. tam da substring eh 2*R[i]+1)
void manacherI() {
    int i,j,k;
    for (i=0,j=0;i<n;i+=k) {
        for (; i-j-1 >= 0 and i+j+1 < n and s[i-j-1] == s[i+j+1]; j++);
        R[i]=j;
        for (k=1;i-k >= 0 and k<=R[i] and R[i-k] != R[i]-k; k++) {
            R[i+k] = min(R[i-k],R[i]-k);
        }
        j = max(0,j-k);
    }
}



int main() {

    for (int i=0;i<26;i++)
        scanf("%d", valor+i);
    scanf("%s", s);
    n = strlen(s);
    for (int i=0;i<n;i++)
        v[i] = valor[ s[i] - 'a' ];

    int raiz = constroi(0, n-1);

    int maior = -0x3f3f3f3f;

    // par
    manacherP();

    for (int i=0;i<n-1;i++)
        if (R[i] > 0) {
            int ini = i+1;
            int fim = i+R[i];
            int tt = 2*query(raiz, ini, fim).first;
            if (tt > maior)
                maior = tt;
        }

    // impar
    manacherI();

    for (int i=0;i<n;i++) {
        if (R[i]==0)
            maior = max(maior, v[i]);
        else {
            int ini = i+1;
            int fim = i+R[i];
            int tt = v[i] + 2*query(raiz, ini, fim).first;
            if (tt > maior)
                maior = tt;
        }
    }

    printf("%d\n", maior);

    return 0;
}
