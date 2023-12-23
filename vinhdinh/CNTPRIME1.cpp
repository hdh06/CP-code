#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int const N = 1e6 + 1;

bool sang[N] = {};
int nop[N];

void init(){
	sang[0] = sang[1] = 1;
	for (ll i = 2; i < N; i++){
		nop[i] = nop[i - 1];
		if (!sang[i]){ 
			for (ll j = i*i; j < N; j += i) sang[j] = 1;
			nop[i] ++;
		}
	}
}

int main(){
	init();
	int k;
	cin >> k;
	while (k--){
		int a, b;
		cin >> a >> b;

		cout << nop[b] - nop[a - 1] << endl;
	}
	return 0;
}