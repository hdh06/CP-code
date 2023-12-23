#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n; ll m; cin >> n >> m;
	vector<int> arr(n + 1);
	
	ll sum = 0;
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		sum += arr[i];
	}
	
	vector<int> b = arr;
	
	sort(b.begin(), b.end(), greater<int>());
	
	ll ans = m / sum * n;
	m -= m / sum * sum;
	for (int i = 1; i <= n - 1; i++){
		sum -= b[i];
		ans += m / sum * (n - i);
		m -= m / sum * sum;
		cerr << ans << "\n";
	}
	
	cout << ans;
	return 0;
}