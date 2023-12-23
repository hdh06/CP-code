#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m, k; cin >> n >> m >> k;
	
	vector<vector<long long> > arr(n + 1, vector<long long> (m + 1, 0));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
			
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){
			arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
		}
	long long ans = LLONG_MIN;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			ans = max(ans, arr[i][j] - arr[max(0, i - k)][j] - arr[i][max(0, j - k)] + arr[max(0, i - k)][max(0, j - k)]);
		}
	}
	cout << ans;
	return 0;
}