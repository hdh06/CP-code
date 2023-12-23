#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	ll a1, b1, c1; cin >> a1 >> b1 >> c1;
	ll a2, b2, c2; cin >> a2 >> b2 >> c2;
	
	cout << setprecision(6) << fixed << 1.0L * (- c1 * b2 + c2 * b1) / (a1 * b2 - a2 * b1); 
	cout << " ";
	cout << setprecision(6) << fixed << 1.0L * (- c1 * a2 + c2 * a1) / (b1 * a2 - b2 * a1);
	return 0;
}