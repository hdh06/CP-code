#include <bits/stdc++.h>

using namespace std;

int const N = 11;

bool vis[N] = {};

vector<int> path;

int n;

void dequy(int i){
	if (i == n + 1){
		for (auto x: path) cout << x << " ";
		cout << endl;
		return;
	}
	for (int x = 1; x <= n; x++)if (!vis[x]){
		vis[x] = true;
		path.push_back(x);
		dequy(i + 1);
		path.pop_back();
		vis[x] = false;
	}
}

int main(){
	cin >> n;
	dequy(1);
	return 0;
}
