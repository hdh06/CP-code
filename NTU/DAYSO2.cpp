#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	vector<int> arr(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	
	long long ans = LLONG_MIN;
	for (int st = 1; st <= 3; st++){
		long long sum = 0;
		for (int i = st; i + 2 <= n; i += 3){
			sum += arr[i] + arr[i + 1] + arr[i + 2];
			ans = max(ans, sum);
			if (sum < 0) sum = 0;
		}
	}
	cout << ans;
	return 0;
}