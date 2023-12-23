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
	P(ll x, ll y): x(x), y(y) {}
	
	double dis(){return sqrtl(x * x + y * y);}
};

P vtc(P A, P B){return P(B.x - A.x, B.y - A.y);}
ll dot(P A, P B){return A.x * B.x + A.y * B.y;}
ll cross(P A, P B){return A.x * B.y - A.y * B.x;}
ll sign(ll x){return (x == 0? 0: (x < 0? -1: 1));}

// check intersect of ray AB and ray CD
bool isRayIntersect(P A, P B, P C, P D){
	ll ABxAC = sign(cross(vtc(A, B), vtc(A, C)));
	ll ABxAD = sign(cross(vtc(A, B), vtc(A, D)));
	ll CDxCA = sign(cross(vtc(C, D), vtc(C, A)));
	ll CDxCB = sign(cross(vtc(C, D), vtc(C, B)));
		
	//four points on the straight line
	if (ABxAC == 0 && ABxAD == 0){
		if (dot(vtc(A, B), vtc(C, D)) >= 0) return true; //two ray point the same direction
		return dot(vtc(A, B), vtc(A, C)) >= 0; //diff dir but C on ray AB
	}		
		
	//three points onthe straight line
	if (ABxAC * ABxAD * CDxCA * CDxCB == 0){
		if (ABxAC == 0 && dot(vtc(A, C), vtc(B, C)) <= 0) return true;
		if (ABxAD == 0 && dot(vtc(A, D), vtc(B, D)) <= 0) return true;
		if (CDxCA == 0 && dot(vtc(C, A), vtc(D, A)) <= 0) return true;
		if (CDxCB == 0 && dot(vtc(C, B), vtc(D, B)) <= 0) return true;
		return false;
	}
	
	//C D on diff side or same side but vtcCD must point to vtcAB which mean ABxAC and ABxCD must have diff sign
	//same for A B on ray CD
	return (ABxAC * ABxAD < 0 || ABxAC * sign(cross(vtc(A, B), vtc(C, D))) < 0)
		&& (CDxCA * CDxCB < 0 || CDxCA * sign(cross(vtc(C, D), vtc(A, B))) < 0);
}

//distance from point X to a ray AB
double disPtoR(P X, P A, P B){
	if (dot(vtc(A, B), vtc(A, X)) >= 0)
		return abs(cross(vtc(A, B), vtc(A, X))) / vtc(A, B).dis();
	return vtc(A, X).dis();
}

int main(){
	P A, B, C, D;
	cin >> A.x >> A.y >> B.x >> B.y;
	cin >> C.x >> C.y >> D.x >> D.y;	
	
	if (isRayIntersect(A, B, C, D))
		cout << 0;
	else{
		double ans = disPtoR(A, C, D);
		ans = min(ans, disPtoR(B, C, D));
		ans = min(ans, disPtoR(C, A, B));
		ans = min(ans, disPtoR(D, A, B));
		cout << setprecision(6) << fixed << ans;
	}
	return 0;
}