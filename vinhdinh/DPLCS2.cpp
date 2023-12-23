#include <bits/stdc++.h>

using namespace std;

int const N = 2001;
int dp[N][N] = {};


int main(){
	string a, b;
	cin >> a >> b;
	a = " " + a;
	b = " " + b;
	for(int i = 1; i < a.length(); i++){
		for (int j = 1; j < b.length(); j++){
			if (a[i] == b[j]){
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	string ans = "";
	for (int i = a.length(), j = b.length(); i > 0 && j > 0;){
		if (a[i] != b[j]){
			if(dp[i][j - 1] > dp[i - 1][j]){
				j--;
			}
			else i --;
		}
		else{
			ans = a[i] + ans;
			i--;
			j--;
		}
	}

	ans.erase(ans.size() - 1, 1);
	cout << ans;
	return 0;
}

