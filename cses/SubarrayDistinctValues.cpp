#include <bits/stdc++.h>

using namespace std;

map<int, int> m;

int main(){
	int n, k; cin >> n >> k;
	vector<int> arr(n + 1); for (int i = 1; i <= n; i++) cin >> arr[i];
	long long ans = 0;
	for (int i = 1, l = 1, cnt = 0; i <= n; i++){
		if (!m[arr[i]])
		while (cnt == k && l < i){
			m[arr[l]]--;
			cnt -= (m[arr[l++]]== 0);
		}
		ans += i - l + 1;// cout << i - l + 1 << " ";
		cnt += (m[arr[i]] == 0);
		m[arr[i]]++;
	}

	cout << ans;
	return 0;
}