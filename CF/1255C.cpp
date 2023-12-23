#include <bits/stdc++.h>

using namespace std;

typedef array<int, 3> iii;

int const N = 1e5 + 1;

iii arr[N];
set<int> g[N];

int main(){
	int n; cin >> n;
	int cnt[N] = {};
	for (int i = 1; i <= n - 2; i++){
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2]; 
		g[arr[i][0]].insert(i);
		g[arr[i][1]].insert(i);
		g[arr[i][2]].insert(i);
		cnt[arr[i][0]]++;
		cnt[arr[i][1]]++;
		cnt[arr[i][2]]++;
	}

	int pos = 0, end = 0;
	for (int i = 1; i <= n; i++)
		if (g[i].size() == 1){
			if (!pos) pos = *g[i].begin();
			else end = i;
		}
	
	int dem = 1;
	while (dem <= n - 3){
		int a, b, c;
		for (int i = 0; i < 3; i++){
			if (g[arr[pos][i]].size() == 1) a = i;
			if (g[arr[pos][i]].size() == 2) b = i;
			if (g[arr[pos][i]].size() == 3) c = i;
			g[arr[pos][i]].erase(pos);
		}

		// cout << pos << "\n";
		cout << arr[pos][a] << " ";
		dem++;
		pos = *g[arr[pos][b]].begin();
	}

	for (auto x: arr[pos]) if (cnt[x] == 3 && x != end)
		cout << x << " ";

	for (auto x: arr[pos]) if (cnt[x] == 2 && x != end)
		cout << x << " ";
	
	cout << end << "\n";
	return 0;
}