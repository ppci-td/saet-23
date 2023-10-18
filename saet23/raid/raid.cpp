#include <bits/stdc++.h>

// errado
using namespace std;

int main() {
    int N, M, sumRaid = 0;
    cin >> N >> M;
    
    vector<int> magias(N);
    vector<int> monstros(M);
    vector<int> somaMagias(N+1);

    for (int i = 0; i < N; i++) {
        cin >> magias[i];
    }

    for (int i = 0; i < M; i++) {
        cin >> monstros[i];
        sumRaid += monstros[i];
    }

    int minCoins = INT_MAX;
    
    somaMagias[0] = 0;
    for (int i = 1; i < N+1; i++) {
        somaMagias[i] = somaMagias[i - 1] + magias[i-1];
    }

    for (int i = 0; i < N+1; i++) {
        int lo = i;
        int hi = N+1;
        
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int sum = somaMagias[mid] - somaMagias[i-1];
            
            if (sum >= sumRaid) {
                if(minCoins > sum)    minCoins = sum;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
    }

    minCoins == INT_MAX ? cout << "-1\n" : cout << minCoins << endl;

    return 0;
}
