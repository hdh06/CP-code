#include <bits/stdc++.h>

using namespace std;

bool ask(int l, int r){
	cout << "? " << l << " " << r << endl;
	vector<int> arr(r - l + 1);
	for (auto &x: arr) cin >> x;
	int cnt = 0;
	for (auto x: arr) if (l <= x && x <= r) cnt++;
	return (cnt & 1);
}

void solve(){
	int n; cin >> n;
	int l = 1, r = n;
	while (l < r){
		int mid = (l + r) >> 1;
		if (ask(l, mid))
			r = mid;
		else l = mid + 1;
	}	
	cout << "! " << l << endl;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}