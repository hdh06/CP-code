#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 27082023
#endif

using namespace std;
typedef long long ll;

struct P{
	ll x, y;
	P(){}
	P(ll x, ll y): x(x), y(y) {}
	
	double dis(){return sqrtl(x * x + y * y);}
};

P vtc(P A, P B){return P(B.x - A.x, B.y - A.y);}
ll dot(P A, P B){return A.x * B.x + A.y * B.y;}
ll cross(P A, P B){return A.x * B.y - A.y * B.x;}
ll sign(ll x){return (x == 0? 0: (x < 0? -1: 1));}

bool isIntersect(P A, P B, P C, P D){
	ll ABxBC = sign(cross(vtc(A, B), vtc(B, C)));
	ll ABxBD = sign(cross(vtc(A, B), vtc(B, D)));
	ll CDxDA = sign(cross(vtc(C, D), vtc(D, A)));
	ll CDxDB = sign(cross(vtc(C, D), vtc(D, B)));

	if (ABxBC == 0 || ABxBD == 0 || CDxDA == 0 || CDxDB == 0){
		if (ABxBC == 0 && dot(vtc(A, C), vtc(B, C)) <= 0) return true;
		if (ABxBD == 0 && dot(vtc(A, D), vtc(B, D)) <= 0) return true;
		if (CDxDA == 0 && dot(vtc(C, A), vtc(D, A)) <= 0) return true;
		if (CDxDB == 0 && dot(vtc(C, B), vtc(D, B)) <= 0) return true;
	}
	
	return (ABxBC * ABxBD < 0 && CDxDA * CDxDB < 0);
}

// dis of point C to line A->B
double disPtL(P A, P B, P C){
	if (dot(vtc(A, B), vtc(A, C)) < 0) 
		return vtc(A, C).dis();
	if (dot(vtc(B, A), vtc(B, C)) < 0)
		return vtc(B, C).dis();
	return abs(cross(vtc(A, B), vtc(A, C))) / vtc(A, B).dis();
}

int main(){
	P A, B; cin >> A.x >> A.y >> B.x >> B.y;
	P C, D; cin >> C.x >> C.y >> D.x >> D.y;
	
	if (isIntersect(A, B, C, D)){
		cout << 0;
	}else{
		double ans = disPtL(C, D, A);
		ans = min(ans, disPtL(C, D, B));
		ans = min(ans, disPtL(A, B, C));	
		ans = min(ans, disPtL(A, B, D));	
		cout << setprecision(6) << fixed << ans;
	}
	return 0;
}