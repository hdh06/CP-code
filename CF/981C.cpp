#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;

vector<int> g[N];

int main(){
	int n; cin >> n;
	for (int i = 1; i < n; i++){
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int pos = -1; bool flag = 0;
	for (int i = 1; i <= n; i++){
		if (g[i].size() > 2){
			if (pos != -1) flag = 1;
			pos = i;
		}
	}

	if (flag){
		cout << "No";
		return 0;
	}
	if (pos == -1) pos = 1;

	cout << "Yes\n";
	vector<array<int, 2> > ans;
	for (int i = 1; i <= n; i++)
		if (g[i].size() == 1 && i != pos)
			ans.push_back({pos, i});
	
	cout << ans.size() << "\n";
	for (auto x: ans) cout << x[0] << " " << x[1] << "\n";
	return 0;
}