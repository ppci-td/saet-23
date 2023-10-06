#include <bits/stdc++.h>

using namespace std;

int main(){

    srand(time(NULL) + clock());

    int n = 100000 - rand()%100;

    printf("%d\n", n);

    //full random
    for(int i = 0; i < n; i++){
        printf("%d ", rand()%100);
        printf("%d ", rand()%100);
        printf("\n");
    }

    //apenas ataque
    /*for(int i = 0; i < n; i++){
        int a = rand()%99 + 1;
        printf("%d ", a);
        printf("%d ", (rand()%a + 1));
        printf("\n");
    }*/

    //apenas defesa
    /*for(int i = 0; i < n; i++){
        int a = (rand()%99 + 1);
        printf("%d ", (rand()%a));
        printf("%d ", a);
        printf("\n");
    }*/

    //random mas com alguns jogadores com ataque = defesa
    /*int s[n][2];
    for(int i = 0; i < n; i++){
        s[i][0] = rand()%100;
        s[i][1] = rand()%100;
    }
    for(int i = 0; i < 1000; i++){
        int a = rand()%n;
        s[a][0] = s[a][1];
    }
    for(int i = 0; i < n; i++){
        printf("%d ", s[i][0]);
        printf("%d ", s[i][1]);
        printf("\n");
    }*/


    return 0;
}
