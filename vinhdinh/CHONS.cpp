#include <bits/stdc++.h>

using namespace std;

int const N = 1001;

int const M = 100001;

int arr[N];

bool dp[M] = {};

int main(){

	int n; 
	cin >> n;

	for (int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	dp[0] = 1;

	int dem = 0;
	for (int i = 1; i <= n; i++){
		for (int j = M - 1; j >= 1; j--){
			if (j - arr[i] >= 0) dp[j] |= dp[j - arr[i]];
		}
	}

	for (int j = 1; j < M; j++) if (dp[j]) dem++;

	cout << dem;

	return 0;
}