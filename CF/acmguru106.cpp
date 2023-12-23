#include <bits/stdc++.h>

using namespace std;


int a, b, c, minX, maxX, minY, maxY;

int egcd(int a, int b, int &x, int &y){
	if (b == 0){
		x = 1, y = 0;
		return a;
	}
	int x1, y1;
	int g = egcd(b, b % a, x1, y1);
	x = y1;
	y = x1 - y1 * (b / a);
	return g;
}

bool eqsol(int a, int b, int c, int &x, int &y, int &g){
	g = egcd(a, b, x, y);
	if (c % g != 0) return 0;
	
	x *= c / g,	y *= c / g;
	
	if (a < 0) x = -x;
	if (b < 0) y = -y;
	
	return 1;
}

int cnt_eqsol(int a, int b, int c, int minX, int maxX, int minY, int maxY){
	int g, x, y;
	if (!eqsol(a, b, c, x, y, g)) return 0;
	
	a /= g, b /= g;
}

int main(){
	cin >> a >> b >> c >> minX >> maxX >> minY >> maxY;
	return 0;
}