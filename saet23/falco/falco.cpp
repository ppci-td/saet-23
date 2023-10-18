#include<bits/stdc++.h>

using namespace std;

int main() {

    long long int t, k;
    string s;
    string o;

    cin >> t >> k;
    cin >> s;

    for(auto c: s)
        o.push_back(((c - 'a' + k) % 26) + 'a');

    cout << o << "\n";
    return 0;
}

