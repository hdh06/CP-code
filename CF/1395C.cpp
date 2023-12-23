#include <bits/stdc++.h>

using namespace std;

int const N = 201;

int n, m; 
int a[N], b[N];


bool check(int t){
	for (int i = 1; i <= n; i++){
		int minn = INT_MAX;
		for (int j = 1; j <= m; j++){
			if ((t | (a[i] & b[j])) == t) minn = min(minn, a[i] & b[j]);
		}
		if (minn == INT_MAX) return false;
	}
	return true;
}

int main(){
	cin >> n >> m;

	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int j = 1; j <= m; j++) cin >> b[j];

	for (int i = 0; i < (1 << 9); i++){
		if (check(i)){
			cout << i << "\n";
			return 0;
		}
	}
	return 0;
}