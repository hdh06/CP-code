#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<int> pos(n + 1), arr(n + 1);
		for (int i = 1; i <= n; i++){
			cin >> arr[i];
			pos[arr[i]] = i;
		}
		
		vector<pair<int, int> > ans;
		
		for (int i = 1; i <= n; i++){
			ans.push_back({i, pos[i]});			
			if (pos[i] - i > 2) ans.push_back({i + 1, pos[i] - 1});\
			swap(arr[i], arr[pos[i]]);
			swap(pos[arr[pos[i]]], pos[i]);
		}
		
		cout << ans.size() << "\n";
		for (auto x: ans) cout << x.first << " " << x.second << "\n";
	}
	return 0;
}