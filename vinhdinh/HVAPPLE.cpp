#include <bits/stdc++.h>

using namespace std;

int const N = 1e4 + 5;

int n, m;
int arr[N];

int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
		
	int ans = 0;
	for (int i = 1; i <= n + 1; i++){
		ans += min(m, arr[i]);
		arr[i] -= min(m, arr[i]);
		arr[i + 1] += arr[i];
	}
	
	cout << ans;
	return 0;
}