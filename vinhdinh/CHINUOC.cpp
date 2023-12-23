#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 20001;

bool sang[N] = {1, 1};
vector<ll> prime;

void init(){
	for (ll i = 2; i < N; i++) if (!sang[i]){
		for (ll j = i*i; j < N; j += i) sang[j] = true;
		prime.push_back(i);
	}
}

int main(){
	init();
	ll n;
	cin >> n;	

	int dem = 0;
	for (int i = 0; i < prime.size(); i++){
		for (int j = i + 1; j < prime.size(); j++){
			if (prime[j]*prime[j]*prime[i]*prime[i] <= n) dem++;
		}
		if (pow(prime[i], 8) <= n) dem++;
	}

	cout << dem;
	return 0;
}