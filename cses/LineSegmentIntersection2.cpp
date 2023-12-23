#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rd);}

struct P{
	ll x, y;
	
	P(){}
	P(ll x, ll y): x(x), y(y) {}
	
	double dis(){return sqrt(x * x + y * y);}
	ll dis2(){return x * x + y * y;}
	ll dot(P A){return x * A.x + y * A.y;}
	ll cross(P A){return x * A.y - y * A.x;}
	double angle(){return y >= 0? acos(x / dis()): 8 * atan(1) - acos(x / dis());}
	double angle(P A){return acos(dot(A) / dis() / A.dis());}
	P operator -(P A){return P(x - A.x, y - A.y);}
	P operator +(P A){return P(x + A.x, y + A.y);}
	P operator *(ll v){return P(x * v, y * v);}
	P operator /(ll v){assert(v != 0);return P(x / v, y / v);}
	
	void read(){cin >> x >> y;}
	void flip90cw(){x = -x, swap(x, y);}
	void flip90cww(){y = -y, swap(x, y);}
	void flip180(){x = -x, y = -y;}
};

int sign(ll x){
	if (x == 0) return 0;
	return (x > 0? 1: -1);
}

bool checkIntersect(P A, P B, P C, P D){
	ll ABC = sign((B - A).cross(C - A));
	ll ABD = sign((B - A).cross(D - A));
	ll CDA = sign((D - C).cross(A - C));
	ll CDB = sign((D - C).cross(B - C));
	
	if (ABC == 0 || ABD == 0 || CDA == 0 || CDB == 0){
		if (ABC == 0 && (C - A).dot(C - B) <= 0) return true;
		if (ABD == 0 && (D - A).dot(D - B) <= 0) return true;
		if (CDA == 0 && (A - C).dot(A - D) <= 0) return true;
		if (CDB == 0 && (B - C).dot(B - D) <= 0) return true;
		return false;
	}
	return ABC * ABD < 0 && CDA * CDB < 0;
}

int main(){
	int t; cin >> t;
	while (t--){
		P A, B, C, D;
		A.read(); B.read(); C.read(); D.read();
		
		cout << (checkIntersect(A, B, C, D)? "YES\n": "NO\n");
	}
	return 0;
}