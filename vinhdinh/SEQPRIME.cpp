#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> p;

void tsang(){
	int const N = 2e4;

	bool sang[N] = {1, 1};

	for (ll i = 1; i < N; i++) if (!sang[i]){
		for (ll j = i*i; j < N; j+=i) sang[j] = true;
		p.push_back(i);
	}
}

int main(){
	tsang();
	int n; 
	cin >> n;

	for (int i = 1; i <= (n>>1)<<1; i++){
		cout << p[i] << " ";
	}

	if (n&1) cout << 2;
	return 0;
}