#include <bits/stdc++.h>

//|-| |_| `/

using namespace std;

int const N = 1002;

string a, b;
int dp[N][N] = {};
bool dir[N][N] = {};

bool xuly(int i, int j){
	
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> a >> b;

	int n = a.size(), m = b.size();

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	a = ' ' + a;
	b = ' ' + b;

	bool flag = 0;

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (a[i] == b[j]){
				// if (a[i] == '0'){
				// 	flag = 1;
				// 	if (dp[i - 1][j - 1] == 0){
				// 		// cout << 0 << " \n"[j == m];
				// 		continue;
				// 	}
				// }
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else{
				dir[i][j] = xuly(i, j);
			}
			cout << dp[i][j] << " \n"[j == m];
		}
	}

	// cout << "DONE" << endl;

	if (dp[n][m] == 0){
		if (flag){
			cout << "1\nLCS MAX NUMBER is 0";
		}
		else{
			cout << "0\nLCS MAX NUMBER is NULL";
		}
	}
	else{
		string ans;
		for (int i = n, j = m; i > 0 && j > 0;){
			if (a[i] == b[j]){
				ans = ans + a[i];
				i--, j--; 
			}
			else{
				if (dir[i][j]) i--;
				else j--;
			}
		}
		while (ans[0] == '0') ans.erase(0, 1);
		cout << ans.size() << endl;
		cout << "LCS MAX NUMBER is " << ans;
	}
	return 0;
}