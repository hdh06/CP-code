#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n, m, k; cin >> n >> m >> k;
	string a, b; cin >> a >> b;	

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	string c;

	int cur = 0, last = 0;
	for (int i = 0, j = 0; i < n && j < m;){
		if (a[i] < b[j]){
			if (last == 1 && cur == k){
				c.push_back(b[j++]);
				last = 2;
				cur = 1;
			}else{
				c.push_back(a[i++]);
				if (last == 1) cur++; else cur = 1;
				last = 1;
			}
		}else{
			if (last == 2 && cur == k){
				c.push_back(a[i++]);
				last = 1;
				cur = 1;
			}else{
				c.push_back(b[j++]);
				if (last == 2) cur++; else cur = 1;
				last = 2;
			}
		}
	}
	cout << c << "\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}