#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;

	vector<int> arr(n + 1);

	for (int i = 1; i <= n; i++) cin >> arr[i];

	int maxn = 0;

	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			maxn = max(maxn, arr[i] - (j - i)*k - arr[j]);
		
	cout << maxn;
	return 0;
}