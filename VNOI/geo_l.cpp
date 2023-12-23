#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ll xA, yA, xB, yB; cin >> xA >> yA >> xB >> yB;
	
	ll a = yB - yA;
	ll b = xA - xB;
	ll c = xA * yB - xB * yA;
	
	cout << a << " " << b << " " <<  - c;
	// ax + by = c;
	return 0;
}