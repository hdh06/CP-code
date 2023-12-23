#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n; cin >> n; ll s; cin >> s;
	vector<int> arr(n);
	for (auto &x: arr) cin >> x;

	map<ll, int> m; 	
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++){
			ll z = arr[i] + arr[j];
			if (m.find(z) == m.end()) m[z] = INT_MAX;
			m[z] = min(m[z], j);
		}

	array<int, 4> ans = {-1, -1, -1, -1};

	for (int i = 0; i < n; i++) if (ans[0] == -1)
		for (int j = i + 1; j < n; j++){
			ll z = s - arr[i] - arr[j];
			if (z < 0) continue;
			if (m.find(z) == m.end()) continue;
			if (m[z] < i){
				ans[1] = m[z]; 
				for (int k = 0; k < ans[1]; k++)
					if (arr[k] + arr[ans[1]] == z){
						ans[0] = k;
						break;
					}
				ans[2] = i;
				ans[3] = j;
				break;
			}
		}
	if (ans[0] == -1) cout << "IMPOSSIBLE";
	else
	for (auto x: ans) cout << x + 1 << " ";
	return 0;
}