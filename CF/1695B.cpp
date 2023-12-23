#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin >> n;
	vector<int> arr(n + 1, INT_MAX);
	for (int i = 1; i <= n; i++) cin >> arr[i];

	int pos = 0;
	for (int i = 1; i <= n; i++) if (arr[i] < arr[pos]) pos = i;
	
	if (n & 1)
		cout << "Mike\n";
	else{
		if (pos & 1)
			cout << "Joe\n";
		else cout << "Mike\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);	
	int t; cin >> t;
	while(t--) solve();
	return 0;
}