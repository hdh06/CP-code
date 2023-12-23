#include <bits/stdc++.h>

// KHU RUNG VINHDINH

using namespace std;

typedef long long ll;

int main(){
	int n, k;
	cin >> n >> k;

	ll arr[1001][1001] = {};

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			int temp;
			cin >> temp;
			arr[i][j] = temp + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
		}	

	ll maxn = 0;
	for (int i = k; i <= n; i++){
		for (int j = k; j <= n; j++){
			maxn = max(maxn, arr[i][j] - arr[i - k][j] - arr[i][j - k] + arr[i - k][j - k]);
		}
	}

	cout << maxn;
	return 0;
}
    