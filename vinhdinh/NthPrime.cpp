#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 2e6;

bool sang[N] = {};
int ithprime[N] = {}, dem = 0;

void init(){
	sang[0] = sang[1] = true;
	for (ll i = 2; i <= N; i++){
		if (!sang[i]){
			for (ll j = i*i; j <= N; j+=i) sang[j] = true;
			ithprime[++dem] = i;
		}
	}
}

int main(){
	init();
	int t; cin >> t;
	while (t--){
		int n;
		cin >> n;
		cout << ithprime[n] << endl;
	}
	return 0;
}