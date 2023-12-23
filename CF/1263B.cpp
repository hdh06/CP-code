#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin >> n;

	map<string, int> is;

	int ans = 0;
	vector<string> v(n + 1);
	for (int i = 1; i <= n; i++) cin >> v[i];
	for (int i = 1; i <= n; i++) is[v[i]]++;
	for (int t = 1; t <= n; t++){
		if (is[v[t]] > 1){
			for (int i = 0; i < 4; i++){
				bool flag = 1;
				for (char j = '0'; j <= '9'; j++) if (j != v[t][i]){
					char tmp = v[t][i];
					v[t][i] = j;
					if (is[v[t]] == 0){
						ans++;
						is[v[t]]++;
						v[t][i] = tmp;
						is[v[t]]--;
						v[t][i] = j;
						flag = 0;
						break;
					}
					v[t][i] = tmp;
				}
				if (!flag) break;
			}
		}
	}	
	cout << ans << "\n";
	for (int i = 1; i <= n; i++) cout << v[i] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}