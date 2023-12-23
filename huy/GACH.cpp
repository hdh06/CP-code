#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

pair<ll,ll> sinhtest(int m, int n){
	ll G = (m + n)/2 - 4;
	ll Y = m*n - G;
	return make_pair(G,Y);
}

int main(){
	ll Y, G;
	cin >> G >> Y;
	if ((G - 4) % 2 != 0){
		cout << -1;
		return 0;
	}
	ll S = -((G + 4)/2), P = Y + G;
	ll delta = S*S - 4*P*1;
	ll candel = sqrt(delta);
	cout << S << " " << P << " " << delta << " " << candel << endl; 
	if (candel*candel != delta || delta < 0){
		cout << -1;
		return 0;
	}
	ll m = (-candel - S)/(2*1), n = (candel - S)/(2*1);
	if (m < 0 || n < 0){
		cout << -1;
		return 0;
	}
	cout << m << " " << n;
	// int m, n;
	// cin >> m >> n;
	// pair<ll,ll> kq = sinhtest(m,n);
	// cout << kq.first << " " << kq.second << endl;
	return 0;
}