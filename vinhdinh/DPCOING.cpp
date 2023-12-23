#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 6;
bool dp[N];
int K, L, m;

void init(){
	dp[0] = 0;
	for (int i = 1; i <= N; i++){
		dp[i] = !dp[i - 1];
		if (i - K >= 0) dp[i] |= !dp[i - K];
		if (i - L >= 0) dp[i] |= !dp[i - L];
	}
}

int main(){
	cin >> K >> L >> m;

	init();

	cout << endl;
	while (m--){
		int temp;
		cin >> temp;
		cout << (dp[temp]?'A':'B');
	}


	return 0;
}