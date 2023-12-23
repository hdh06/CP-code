#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 2e5 + 1;
bool sang[N] = {1, 1};

void init(){
	for (ll i = 2; i < N; i++) if (!sang[i])
		for (ll j = i * i; j < N; j += i) sang[j] = true;
}

int main(){
	init();
	int a, b; cin >> a >> b;
	for (int i = a; i <= b; i++) if (!sang[i]) cout << i << "\n";	
	return 0;
}