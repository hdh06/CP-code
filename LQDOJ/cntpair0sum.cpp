#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;

	map<int, int> m;
	int arr[200001];
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		if (arr[i] <= 0) m[arr[i]]++;
	}

	long long ans = 1LL * m[0] * (m[0] - 1)/2;

	for (int i = 1; i <= n; i++) if (arr[i] > 0)
		ans += m[-arr[i]];
	
	cout << ans;
	return 0;
}