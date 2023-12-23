#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct P{	
	ll x, y; 
	P(){}
	P(int x, int y) : x(x), y(y) {}
	
	double dis(){
		return sqrtl(x * x + y * y);
	}
};

P vtc(P A, P B){
	return P(B.x - A.x, B.y - A.y);
}

ll cross(P A, P B){
	return A.x * B.y - A.y * B.x;
}

int main(){
	P A, B, C;
	cin >> A.x >> A.y;
	cin >> B.x >> B.y;
	cin >> C.x >> C.y;
	
	cout << setprecision(6) << fixed << 1.0L * abs(cross(vtc(B, C), vtc(B, A))) / vtc(B, C).dis();
	return 0;
}