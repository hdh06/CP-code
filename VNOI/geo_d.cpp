#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct P{
	ll x, y;
	P(){}
	P(ll x, ll y): x(x), y(y) {}
	
	double dis(){
		return sqrtl(x * x + y * y);
	}
};

P vtc(P A, P B){return P(B.x - A.x, B.y - A.y);}

int main(){
	P X, Y, Z;
	cin >> X.x >> X.y;
	cin >> Y.x >> Y.y;
	cin >> Z.x >> Z.y;
	
	P a = vtc(X, Y);
	P b = vtc(X, Z);
	
	double A = a.x * b.dis() - b.x * a.dis();
	double B = a.y * b.dis() - b.y * a.dis();
	double C = - (X.x * A + X.y * B);
	
	cout << setprecision(6) << fixed << A / B << " " << 1 << " " << C / B;
	return 0;
}