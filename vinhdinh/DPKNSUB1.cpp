#include <bits/stdc++.h>

using namespace std;

int const N = 101;

int arr[N];
int sum;
bool memo[N][100000] = {}, ismemo[N][100000];

bool dequy(int i, int s){
	if (ismemo[i][s]) return memo[i][s];
	if (i == 0){
		if (s == sum - s) return true;
		return false;
	}
	memo[i][s] = dequy(i - 1, s - arr[i]) | dequy(i - 1, s);
	ismemo[i][s] = true;
	return memo[i][s];
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;	
		sum = 0;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			sum += arr[i];
		}

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= sum; j++) memo[i][j] = -1, ismemo[i][j] = false;
		}

		if(dequy(n, sum)) cout << "YES";
		else cout << "NO";
		cout << '\n';
	}
	return 0;
}