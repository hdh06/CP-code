#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 1;

int main(){
	int n; cin >> n;
	int arr[N];
	for (int i = 1; i <= n; i++) cin >> arr[i];

	int cnt[N] = {};
	for (int i = 1; i <= n; i++){
		for (int j = 1; j * j <= arr[i]; j++) if (arr[i] % j == 0){
			cnt[j]++;
			if (arr[i] / j != j) cnt[arr[i] / j]++;
		}
	}

	int ans = 1;
	for (int i = 1; i < N; i++) if (cnt[i] >= 2)
		ans = max(ans, i);
	cout << ans;
	return 0;
}