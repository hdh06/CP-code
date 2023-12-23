#include <bits/stdc++.h>

using namespace std;

int const N = 5001;

#define F first
#define S second

int main(){
	int n;
	cin >> n;

	pair<int,int> arr[N];

	for (int i = 1; i <= n; i++){
		cin >> arr[i].F >> arr[i].S;
	}

	sort(arr + 1, arr + n + 1);

	int dp[N] = {};

	for (int i = 1; i <= n; i++){
		dp[i] = 1;
		for (int j = i - 1; j >= 1; j--) if (arr[j].S < arr[i].F){
			dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	cout << *max_element(dp + 1, dp + n + 1);

	return 0;
}