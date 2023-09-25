#include <bits/stdc++.h>

using namespace std;

char s[500050];

int main() {

    srand(time(NULL) + clock());
    memset(s,0,sizeof(s));

    int n = 500000 - rand()%10;
    for (int i=0;i<26;i++) {
        if (i) printf(" ");
        printf("%d", rand()%2001 - 1000);
    }
    printf("\n");

    // td igual
/*    char l = rand()%26 + 'a';
    for (int i=0;i<n;i++)
        printf("%c", l);
    printf("\n");*/

    // full random
/*    for (int i=0;i<n;i++) s[i] = rand()%26 + 'a';
    printf("%s\n", s);*/

    // full random mas com palindromes hardcoded
/*    for (int i=0;i<n;i++) s[i] = rand()%26 + 'a';
    for (int tt=0;tt<10000;tt++) {
        int a = rand()%n;
        int b = rand()%n;
        if (a > b) swap(a,b);
        int i = a, j = b;
        while (i <= j) {
            s[i] = s[j];
            i++;
            j--;
        }
    }
    printf("%s\n", s);*/

    // "quase" todo mundo igual
/*    char l = rand()%26 + 'a';
    for (int i=0;i<n;i++) s[i] = l;
    for (int i=0;i<1000;i++)
        s[rand()%n] = rand()%26 + 'a';
    printf("%s\n", s);*/

    // zig zag com perm
    char p[26];
    for (int i=0;i<26;i++)
        p[i] = 'a' + i;
    for (int i=0;i<26;i++) {
        int tt = rand()%(26-i);
        swap(p[i], p[i+tt]);
    }
    int l = 0;
    int dir=0;
    for (int i=0;i<n;i++) {
        s[i] = p[l];
        if (dir==0) {
            if (l==25) dir=1;
            else l++;
        } else {
            if (l==0) dir=0;
            else l--;
        }
    }
    printf("%s\n", s);

    return 0;
}
