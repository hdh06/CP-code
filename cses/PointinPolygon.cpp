#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct P{
	ll x, y;
	P(){}
	P(ll _x, ll _y){x = _x, y = _y;}
};

P vtc(P a, P b){
	return {b.x - a.x, b.y - a.y};
}

ll cross(P a, P b){
	return a.x * b.y - a.y * b.x;
}

ll ccw(P a, P b, P c){
	return cross(vtc(a, b), vtc(b, c));
}
bool same(P a, P b){
	return (a.x == b.x && a.y == b.y);
}

int n, m;
vector<P> poly;
int check(P pt){
	int winding = 0;
	for (int i = 1; i <= n; i++){
		if (same(pt, poly[i])) return 0;
		int j = i + 1;
		if (pt.y == poly[i].y && poly[i].y == poly[j].y){
			if (min(poly[i].x, poly[j].x) <= pt.x && 
				pt.x <= max(poly[i].x, poly[j].x))
					return 0;
		}else{
			bool below = pt.y < poly[i].y;
			if (below != pt.y < poly[j].y){
				ll crs = ccw(pt, poly[i], poly[j]);
				if (crs == 0) return 0;
				if ((crs > 0) == below)
					winding += below ? 1: -1;
			}
		}
	}
	return winding ? 1: -1;
}

int main(){
 	cin >> n >> m;			
 	poly.resize(n + 2);
	for (int i = 1; i <= n; i++)
		cin >> poly[i].x >> poly[i].y;
	poly[n + 1] = poly[1];
	
	while (m--){
		P p; cin >> p.x >> p.y;
		int ans = check(p);
		if (ans == 0) cout << "BOUNDARY\n";
		if (ans == 1) cout << "INSIDE\n";
		if (ans == -1) cout << "OUTSIDE\n";
	}	
	return 0;
}