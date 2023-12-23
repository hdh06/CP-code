#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n, m, k;
	cin >> n >> m >> k;

	ll arr[701][701] = {};

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			int temp;
			cin >> temp;
			arr[i][j] = temp + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
		}	

	ll maxn = 0;
	for (int i = k; i <= n; i++){
		for (int j = k; j <= m; j++){
			maxn = max(maxn, arr[i][j] - arr[i - k][j] - arr[i][j - k] + arr[i - k][j - k]);
		}
	}

	cout << maxn;
	return 0;
}