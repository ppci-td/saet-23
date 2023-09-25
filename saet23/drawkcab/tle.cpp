// O(N^3)

#include <bits/stdc++.h>

#define SIZE 500050

using namespace std;

int valor[32];
char s[SIZE];
int n;

int pega(int ini, int fim) {
    int i=ini, j=fim;
    int soma=0;
    while (i<=j) {
        if (s[i] != s[j]) return -0x3f3f3f3f;
        soma += valor[ s[i]-'a' ];
        if (i != j) soma += valor[ s[j] -'a'];
        i++;
        j--;
    }
    return soma;
}

int main() {

    for (int i=0;i<26;i++)
        scanf("%d", valor+i);
    scanf("%s", s);
    n = strlen(s);
    int maior = -0x3f3f3f3f;
    for (int i=0;i<n;i++)
        for (int j=i;j<n;j++) {
            int tt = pega(i,j);
            if (tt > maior)
                maior = tt;
        }
    printf("%d\n", maior);

    return 0;
}
