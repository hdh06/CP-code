#include <bits/stdc++.h>

using namespace std;

int const N = 1e4 + 1;

int main(){
	int n; cin >> n;
	int arr[4][N];
	for (int i = 0; i < 4; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];

	int dp[N][1 << 4] = {};

	for (int j = 1; j <= n; j++)
		for (int ma = 0; ma < (1 << 4); ma++)
			for (int mb = 0; mb < (1 << 4); mb++){
				if ((ma & mb) == 0 && (ma & (ma << 1)) == 0){
					int x = dp[j - 1][mb];
					for (int i = 0; i < 4; i++) if (ma & (1 << i))
						x += arr[i][j];
					dp[j][ma] = max(dp[j][ma], x);
				}
			}
			
	int maxx = INT_MIN;
	for (int i = 0; i < 4; i++)
		maxx = max(maxx, *max_element(arr[i] + 1, arr[i] + n + 1));

	if (maxx < 0)
		cout << maxx;
	else cout << *max_element(dp[n], dp[n] + (1 << 4));
	return 0;
}