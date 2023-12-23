#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<ll> V;
typedef complex<ll> P;

#define X real()
#define Y imag()

ll cross(V x, V y){
	return (conj(x)*y).Y;
}

bool cbe(P A, P B){
	if (A.X < B.X) return true;
	if (A.X == B.X){
		if (A.Y < B.Y) return true; 
	}
	return false;
}

void sswap(P &A, P &B){
	if (cbe(B, A)) swap(A, B);
}

int state(ll n){
	if (n < 0) return -1;
	if (n == 0) return 0;
	if (n > 0) return 1;
}

int locate(P A, P B, P C){
	return state(cross(C - A, B - C));
}

int main(){
	int t; cin >> t; 
	while(t--){
		ll x[5], y[5];
		for (int i = 1; i <= 4; i++){
			cin >> x[i] >> y[i];
			// cout << "{" << x[i] << "," << y[i] << "}" << endl;
		} 
		P A(x[1],y[1]), B(x[2], y[2]), C(x[3], y[3]), D(x[4], y[4]);
		if (A == C || A == D || B == C || B == D){
			cout << "YES";
		}
		else if (locate(A, B, C) == 0 && locate(A, B, D) == 0){
			sswap(A, B); sswap(C, D);
			if ((cbe(A, C) && cbe(C, B)) || (cbe(A, D) && cbe(D, B)) || (cbe(C, A) && cbe(A, D)) || (cbe(C, B) && cbe(B, D))) cout << "YES";
			else cout << "NO";
			// cout << A << " " << B << " " << C << " " << D << endl;
			// cout << "BEDBUG: " << cbe(D, A) << "&&" << cbe(C, B);
		}
		else if ((locate(A, B, C)*locate(A, B, D)) <= 0 && (locate(C, D, A)*locate(C, D, B)) <= 0){
			cout << "YES";
		}
		else cout << "NO";
		// cout << "BEDBUG: " << locate(A, B, C)*locate(A, B, D) << " " << locate(C, D, A) *locate(C, D, B) << endl;
		// cout << abs(A) << " " << abs(B) << abs(C) << " " << abs(D) << endl;
		cout << endl;
	}

	return 0;
}