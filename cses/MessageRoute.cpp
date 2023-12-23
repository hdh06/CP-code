#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 5;

vector<int> graph[N];
bool isvisited[N] = {}; 
int truyvet[N], dis[N];


int main(){
	int n, m;
	cin >> n >> m;

	while(m--){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	truyvet[1] = 0; dis[1] = 0;

	for (int i = 1; i <= n; i++) dis[i] = INT_MAX;

	queue<int> myque;

	myque.push(1);

	while(!myque.empty()){
		int v = myque.front();
		myque.pop();

		if (isvisited[v]) continue;
		isvisited[v] = true;

		if (v == n) continue;

		for (auto u: graph[v]){
			if (!isvisited[u] && dis[u] > dis[v] + 1) {
				truyvet[u] = v;
				dis[u] = dis[v] + 1;
				myque.push(u);
			}
		}
	}

	if (isvisited[n]){
		vector<int> duongdi;
		int dem = 1;
		for (int i = n; i != 1; i = truyvet[i]){
			duongdi.push_back(i);
			// cout << i << endl;
			dem ++;
		}
		reverse(duongdi.begin(), duongdi.end());
		cout << dem << endl << 1 << " ";

		for (auto u: duongdi){
			cout << u << " ";
		}
	}
	else cout << "IMPOSSIBLE";
	return 0;
}