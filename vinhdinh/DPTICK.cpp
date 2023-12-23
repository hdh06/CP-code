#include <bits/stdc++.h>

using namespace std;

int const N = 60001;

int main(){
	int n;
	cin >> n;
	int s[N], d[N];

	for (int i = 1; i <= n; i++){
		cin >> s[i];
	}

	for (int i = 1; i <= n - 1; i++){
		cin >> d[i];
	}

	int f[N] = {0,s[1]};

	for (int i = 2; i <= n; i++){
		f[i] = min(f[i - 2] + d[i - 1], f[i - 1] + s[i]);
	}

	cout << f[n];
	return 0;
}