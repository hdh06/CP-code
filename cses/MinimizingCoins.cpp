#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 1;
int memo[N] = {};
int n, s;
vector<int> arr;
int const INF = 1e6 + 1;

int dq(int sum){
	if (sum < 0) return INF;
	if (sum == 0) return 0;
	if (memo[sum] != 0) return memo[sum]; 

	int minn = INF;
	for (auto a: arr){
		minn = min(minn, dq(sum - a) + 1);
	} 
	memo[sum] = minn;
	return memo[sum];
}

int main(){
	cin >> n >> s;
	while(n--){
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	int kq = dq(s);
	cout << ((kq == INF)?-1:kq);
	return 0;
}