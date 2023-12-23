#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n, k; 
	cin >> n >> k;

	vector<ll> arr(n, 0);

	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr.begin(), arr.end());

	ll curr = 0;
	bool phase = 0;
	int ans = 0;

	for (int i = 1; i < n; i++) if (curr <= i){
		if (phase == 0){
			if (arr[i] - arr[curr] > k){
				ans ++;
				curr = i - 1;
				phase = 1;
			}
		}
		if (phase == 1){
			if (arr[i] - arr[curr] > k){
				curr = i;
				phase = 0;
			}
		}
	}

	if (phase == 0 && arr[n - 1] - arr[curr] <= k) ans++;

	cout << ans;
	return 0;
}