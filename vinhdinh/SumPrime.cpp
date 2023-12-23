#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e6 + 1;

bool sang[N] = {};
ll sum[N];

void init(){
	sang[0] = sang[1] = true;
	for (ll i = 2; i <= N; i++) {
		if (!sang[i]){
			for (ll j = i*i; j <= N; j += i) sang[j] = true;
			sum[i] = sum[i - 1] + i;
		}
		else sum[i] = sum[i - 1];
	}
}

int main(){
	init();
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << sum[n] << endl;
	}
	return 0;
}