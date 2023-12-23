#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 1e6 + 1;

int uoc[N] = {0, 1};
bool sang[N] = {1, 1};

void init(){
	for (ll i = 2; i < N; i++) uoc[i] = 1;
	for (ll i = 2; i < N; i++){
		if (!sang[i]){
			for (ll j = i*i; j < N; j+=i){
				sang[j] = true;
			}
			for (ll j = i; j < N; j += i){
				ll dem = 0;
				for (ll x = j; x % i == 0; x /= i) dem++;
				uoc[j]+= uoc[j]*dem;
			}
		}
	}
}

ll xuly(int i){
	return uoc[i];
}

int main(){
	init();
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	long long tong = 0;
	while (n--){
		ll temp;
		cin >> temp;
		tong += temp*xuly(temp);
	}

	cout << tong;

	// for (int i = 1; i < 100; i++) cout << i << " " << xuly(i) << endl;
	return 0;
}
