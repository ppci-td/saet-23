#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M, sumRaid = 0;
    cin >> N >> M;
    
    vector<int> magias(N);
    vector<int> monstros(M);

    for (int i = 0; i < N; i++) {
        cin >> magias[i];
    }

    for (int i = 0; i < M; i++) {
        cin >> monstros[i];
        sumRaid += monstros[i];
    }

    int minCoins = INT_MAX;

    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += magias[k];
            }
            if (sum >= sumRaid and minCoins > sum) {
                minCoins = sum;
            }
        }
    }

    minCoins == INT_MAX ? cout << "-1\n" : cout << minCoins << endl;

    return 0;
}
