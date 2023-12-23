#include <bits/stdc++.h>

using namespace std;

struct P{
	int x, y;
	P(){}
	P(int x, int y): x(x), y(y) {}

	void read(){cin >> x >> y;}
	void print(){cout << x << " " << y;}
};

P vtc(P A, P B){return P(B.x - A.x, B.y - A.y);}
int dot(P A, P B){return A.x * B.x + A.y * B.y;}
P sum(P A, P B){return P(A.x + B.x, A.y + B.y);}

int main(){
	P A, B, C;
	A.read(), B.read(), C.read();
	
	if (dot(vtc(A, B), vtc(A, C)) == 0)
		sum(A, sum(vtc(A, B), vtc(A, C))).print();
	if (dot(vtc(B, A), vtc(B, C)) == 0)
		sum(B, sum(vtc(B, A), vtc(B, C))).print();
	if (dot(vtc(C, A), vtc(C, B)) == 0)
		sum(C, sum(vtc(C, A), vtc(C, B))).print();

	return 0;
}