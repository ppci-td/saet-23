#include <bits/stdc++.h>

using namespace std;

int k;
char s[1024];

int main() {

    scanf("%d", &k);
    scanf("%s", s);
    for (int i=0;s[i];i++)
        printf("%c", ((s[i]-'A')-k+26)%26 + 'A' );
    printf("\n");

    return 0;
}
