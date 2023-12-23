#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<ll> P;
typedef complex<ll> V;

#define X real();
#define Y imag();

int main(){
	int t;
	cin >> t; 

	while (t --){
		array<array<int,2>, 4> p;
		cin >> p[1][0] >> p[1][1] >> p[2][0] >> p[2][1] >> p[3][0] >> p[3][1];
		P A = {p[1][0], p[1][1]}, B = {p[2][0], p[2][1]}, C = {p[3][0], p[3][1]};
		V AC = C - A, CB = B - C;
		ll tvh = (conj(AC)*CB).Y;
		if (tvh < 0) cout << "LEFT";
		else if (tvh > 0) cout << "RIGHT";
		else cout << "TOUCH";
		cout << endl;

	}
	return 0;
}