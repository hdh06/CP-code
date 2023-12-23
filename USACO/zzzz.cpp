#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e7;

bool sang[N];

void init(){
	for (int i = 2; i < N; i++) sang[i] = 1;
	
	for (ll i = 2; i < N; i++) if (sang[i] == 1)
		for (ll j = i * i; j < N; j += i)
			sang[j] = 0;
}

int main(){
	init();
	
	for (int i = 0; i < 100; i++) if (sang[i])
		cout << i << "\n";
	return 0;
}