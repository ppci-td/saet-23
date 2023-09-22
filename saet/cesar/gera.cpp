#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("%s k\n", argv[0]);
        return 0;
    }

    srand(time(NULL) + clock());

    printf("%s\n", argv[1]);
    int n = 1000-(rand()%10);
    for (int i=0;i<n;i++)
        printf("%c", 'A'+(rand()%26));
    printf("\n");

    return 0;
}
