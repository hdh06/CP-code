#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll calc(ll a, ll b){
	return b*(b + 1)/2 - a*(a - 1)/2;
}

int main(){
	ll L, R;
	cin >> L >> R;

	ll l = L, r = R, minn = LLONG_MAX, minp = 0;
	while(l < r){
		ll mid = (l + r)/2;
		// cout << l << " " << mid << " " << r << endl;

		ll cL = calc(L, mid);
		ll cR = calc(mid + 1, R);


		// cout << cL << " " << cR << endl;
		if (minn > abs(cL - cR)){
			minn = abs(cL - cR);
			minp = mid;
		}
		if (cL < cR) l = mid + 1;
		if (cR < cL) r = mid;
		if (cR == cL){
			cout << mid;
			return 0;
		}
	}

	cout << minp;
	return 0;
}