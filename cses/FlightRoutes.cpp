#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef array<ll, 2> ii;

int const N = 1e5 + 1;

vector<ii> graph[N];
int cnt[N] = {};
int n, m, k;

int main(){
	cin >> n >> m >> k;
	while(m--){
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({v, w});
	}

	priority_queue<ii> myque;

	myque.push({0, 1});

	vector<ll> ans;

	while (cnt[n] < k){
		int v = myque.top()[1]; ll wv = -myque.top()[0];
		myque.pop();

		if (cnt[v] == k) continue;
		cnt[v] ++ ;

		if (v == n){
			ans.push_back(wv);
		}

		for (auto u: graph[v]) myque.push({-wv-u[1], u[0]});
	}

	for (auto x: ans) cout << x << " ";
	return 0;
}