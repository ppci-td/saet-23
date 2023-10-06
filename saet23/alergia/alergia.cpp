#include <bits/stdc++.h>

int N, A[100], R[100];

using namespace std;

int main() {
    scanf("%d", &N);

    for(int i = 0; i<N; ++i) {
        scanf("%d", &R[i]);
    }
    for(int i = 0; i<N; ++i) {
        scanf("%d", &A[i]);
    }

    bool podeDar = true;
    for(int i = 0; i<N; ++i) {
        if(R[i] == 1 and A[i] == 1) {
            podeDar = false;
        }
    }
    
    if(podeDar) {
        printf("S\n");
    }
    else {
        printf("N\n");
    }

    return 0;
}
