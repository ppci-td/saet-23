#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M, sumRaid = 0;
    cin >> N >> M;
    
    vector<int> magias(N);
    vector<int> monstros(M);
    vector<int> somaMagias(N);

    for (int i = 0; i < N; i++) {
        cin >> magias[i];
    }

    for (int i = 0; i < M; i++) {
        cin >> monstros[i];
        sumRaid += monstros[i];
    }

    int minCoins = INT_MAX;

    somaMagias[0] = magias[0];
    for (int i = 1; i < N; i++) {
        somaMagias[i] = somaMagias[i - 1] + magias[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            int sum = somaMagias[j] - somaMagias[i-1];
            if (sum >= sumRaid and minCoins > sum) {
                minCoins = sum;
            }
        }
    }

    minCoins == INT_MAX ? cout << "-1\n" : cout << minCoins << endl;

    return 0;
}
