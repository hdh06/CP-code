#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1000
#endif

using namespace std;
typedef long long ll;

struct P{
	ll x, y;
	P(){}
	P(ll x, ll y) : x(x), y(y) {}
	
	double dis(){
		return sqrtl(x * x + y * y);
	}
};

P vtc(P A, P B){
	return {B.x - A.x, B.y - A.y};
}

ll cross(P A, P B){
	return A.x * B.y - A.y * B.x;
}

double angle(P A, P B){
	return acos(1.0L * (A.x * B.x + A.y * B.y) / (A.dis() * B.dis())); 
}

int main(){
	P A, B, C; cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
	
	P z = vtc(B, C);
	swap(z.x, z.y);
	z.x = -z.x;
	
	ll l = cross(z, vtc(A, B));
	ll r = cross(z, vtc(A, C));
	
	if (angle(vtc(B, A), vtc(B, C)) <= 2.0L * atan(1)){
		// assert(0);
		cout << setprecision(6) << fixed << 1.0L * abs(cross(vtc(A, B), vtc(A, C))) / vtc(B, C).dis();
	}else{
		cout << setprecision(6) << fixed << vtc(A, B).dis();
	}
	return 0;
}