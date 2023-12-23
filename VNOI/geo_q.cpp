#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct P{
	ll x, y;
	P(){}
	P(int x, int y) : x(x), y(y) {}
};

P vtc(P A, P B){return P(B.x - A.x, B.y - A.y);}

ll dot(P A, P B){return A.x * B.x + A.y * B.y;}

ll cross(P A, P B){return A.x * B.y - A.y * B.x;}

int main(){
	P P, A, B;
	cin >> P.x >> P.y;
	cin >> A.x >> A.y;
	cin >> B.x >> B.y;
	
	if (cross(vtc(A, P), vtc(A, B)) == 0 && dot(vtc(A, P), vtc(A, B)) >= 0 && dot(vtc(B, P), vtc(B, A)) >= 0)
		cout << "YES\n";
	else 
		cout << "NO\n";
	return 0;
}