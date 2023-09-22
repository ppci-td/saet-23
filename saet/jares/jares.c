#include <stdio.h>

int main() {

    int n;

    scanf("%d", &n);
    if (n>0 && (n%2)==0 && (n%10)!=0)
        printf("sim\n");
    else
        printf("nao\n");

    return 0;
}
