#include <bits/stdc++.h>

using namespace std;

int const N = 5001;

typedef pair<int,int> ii;
#define F first
#define S second

int dp[N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; 
	cin >> n;

	vector<ii> arr(n);

	for (int i = 0 ; i < n; i++){
		cin >> arr[i].F >> arr[i].S;
		dp[i] = 1;
	}
	sort(arr.begin(), arr.end());

	for (int i = 1; i < n; i++){
		for (int j = i - 1; j >= 0; j--){
			if (arr[j].F <= arr[i].F && arr[j].S <= arr[i].S) dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	cout << n - *max_element(dp, dp + n);
	return 0;
}