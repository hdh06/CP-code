#include <bits/stdc++.h>

using namespace std;

typedef double db;

void solve(){
	int n; cin >> n;
	vector<int> arr(n);
	for (auto &x: arr) cin >> x;

	sort(arr.begin(), arr.end());

	vector<int> p;
	for (int i = 1; i < n; i++){
		if (arr[i] == arr[i - 1]){
			p.push_back(arr[i]);
			i++;
		}
	}

	sort(p.begin(), p.end());

	int minn = INT_MAX, curr = 1;
	int x = -1, y = -1;
	for (int i = 1; i < p.size(); i++){
		if (1LL * (p[i] * p[i] + p[i - 1] * p[i - 1]) * curr < 1LL * minn * p[i] * p[i - 1]){
			minn = p[i] * p[i] + p[i - 1] * p[i - 1];
			curr = p[i] * p[i - 1];
			x = p[i], y = p[i - 1];
		}
	}
	cout << x << " " << x << " " << y << " " << y << "\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}
