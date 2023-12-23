#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1001
#endif

using namespace std;

int const N = 4e6 + 1; 

void turn(vector<int> &p, int del){
	int tmp = p[3 + del];
	p[3 + del] = p[7 + del];
	p[7 + del] = p[8 + del];
	p[8 + del] = p[5 + del];
	p[5 + del] = p[1 + del];
	p[1 + del] = p[0 + del];
	p[0 + del] = tmp;
}

int main(){
	map<vector<int>, int> ids;
	vector<int> rids[N];
	
	vector<int> p = {0, 0, 1, 2, 3, 4, 5, 6, 7, 8};
	int id = 0;
	do{
		ids[p] = ++id;
		rids[id] = p;
	}while (next_permutation(p.begin(), p.end()));
	
	vector<int> g[N];
	
	for (int i = 1; i < N; i++){
		p = rids[i];
		turn(p, 1);
		g[i].push_back(ids[p]);
		p = rids[i];
		turn(p, 2);
		g[i].push_back(ids[p]);
	}
	
	int dis[N] = {};
	for (int i = 0; i < N; i++) dis[i] = INT_MAX;
	
	p = {1, 2, 3, 8, 0, 0, 4, 7, 6, 5};
	
	dis[ids[p]] = 0;
	queue<int> que;
	que.push(ids[p]);
	while (!que.empty()){
		int v = que.front();
		que.pop();
		for (auto u: g[v])
			if (dis[u] > dis[v] + 1)
				dis[u] = dis[v] + 1, que.push(u);
	}
	
	for (auto &x: p) cin >> x;
	
	cout << dis[ids[p]];
	return 0;
}