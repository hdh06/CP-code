#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k;

	int has[1001] = {};

	int sum = 0;
	int ans = 0;
	while(n--){
		int x; 
		cin >> x; 
		sum += x;
		ans += has[k - sum];
		has[sum]++;
	}

	cout << ans;
	return 0;
}