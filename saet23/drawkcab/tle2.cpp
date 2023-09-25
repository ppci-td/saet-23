// O(N^2)

#include <bits/stdc++.h>

#define SIZE 500050

using namespace std;

int valor[32];
char s[SIZE];
int n;

int main() {

    for (int i=0;i<26;i++)
        scanf("%d", valor+i);
    scanf("%s", s);
    n = strlen(s);
    int maior = -0x3f3f3f3f;
    for (int i=0;i<n;i++) {
        int soma=valor[ s[i]-'a' ];
        int j=1;
        while (i-j >= 0 and i+j < n and s[i-j]==s[i+j]) {
            soma += valor[ s[i-j]-'a' ]*2;
            if (soma > maior) maior = soma;
            j++;
        }
        if (soma > maior) maior = soma;
        soma = 0;
        j = 0;
        while (i-j >= 0 and i+1+j < n and s[i-j]==s[i+1+j]) {
            soma += valor[ s[i-j]-'a' ]*2;
            if (soma > maior) maior = soma;
            j++;
        }
    }
    printf("%d\n", maior);

    return 0;
}
