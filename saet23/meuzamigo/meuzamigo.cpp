#include <iostream>
#include<bits/stdc++.h>
#include<chrono>
using namespace std;

#define MAX 10000100

typedef unsigned long long int ll;
vector<ll> s[MAX];
array<bool, MAX> visited = {false};
ll max_depth = 0;

class Timer
{
public:
    Timer() : beg_(clock_::now()) {}
    void reset() { beg_ = clock_::now(); }
    double elapsed() const { 
        return std::chrono::duration_cast<second_>
            (clock_::now() - beg_).count(); }

private:
    typedef std::chrono::high_resolution_clock clock_;
    typedef std::chrono::duration<double, std::ratio<1> > second_;
    std::chrono::time_point<clock_> beg_;
};


void dfs(ll k, ll depth){
	if (visited[k]) return;
	// printf("%lld depth: %lld v: %d\n", k, depth, visited[k]);
	max_depth = max(depth, max_depth);
	visited[k] = true;
	for(auto neighbour: s[k])
		dfs(neighbour, depth+1);
	return;	
}


void solve(){
	ll N, a, b;
	cin >> N;
	while(N--){
		cin >> a >> b;
		s[a].push_back(b);
		s[b].push_back(a);
	}
	dfs(1,0);
	// cout << s[2].size() << endl;
	cout << max_depth<< endl;
}

int main()
{
	// Timer tmr;
	solve();
	// cout << tmr.elapsed() << endl;
    return 0;
}