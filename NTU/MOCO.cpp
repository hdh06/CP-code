#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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
	void print(){cout << x << " " << y << " ";}
	void flip90cw(){x = -x, swap(x, y);}
	void flip90cww(){y = -y, swap(x, y);}
	void flip180(){x = -x, y = -y;}
	P flip180_2(){return P(-x, -y);}
};

int main(){
	P A, B, C, D; A.read(), B.read(), C.read(), D.read();
	
	
	
	P AB = B - A;
	P BC = C - B;
	P CD = D - C;
	P DA = A - D;
	
	if (AB.cross(CD) == 0 && BC.cross(DA) == 0){
		if (AB.dot(DA.flip180_2()) == 0 && BC.dot(AB.flip180_2())){
			if (AB.dis2() == BC.dis2()) cout << 1;
			else cout << 2;
		}else{
			if (AB.dis2() == BC.dis2()) cout << 3;
			else cout << 4;
		}
	}else cout << 5;
	return 0;
}