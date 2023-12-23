#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
struct pt{
	ll x, y, id, sid;
};
 
int const N = 5e4 + 1;
 
pt pts[N], rpts[N];
int a = 0, b = 1;
 
bool cmp_x(pt a, pt b){return a.x < b.x;}
bool cmp_y(pt a, pt b){return a.y < b.y;}
 
ll edu(pt a, pt b){
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}
 
void find(int l, int r){
	if (r <= l) return;
 
	if (l + 1 == r){
		if (edu(rpts[a], rpts[b]) > edu(pts[l], pts[r]))
			a = pts[r].sid, b = pts[l].sid;
		if (pts[l].y > pts[r].y) 
			swap(pts[l], pts[r]);
		return;
	}
 
	int mid = (l + r)/2;
	int midx = pts[mid].x;
	find(l, mid);
	find(mid + 1, r);
 
	pt sub[N];
	merge(pts + l, pts + mid + 1, pts + mid + 1, pts + r + 1, sub, cmp_y);
 
	copy(sub, sub + r - l + 1, pts + l);
 
	int dem = 0;
	for (int i = l; i <= r; i++) if (abs(pts[i].x - midx) < edu(rpts[a], rpts[b])){
		for (int j = dem - 1; j >= 0 && pts[i].y - sub[j].y < edu(rpts[a], rpts[b]); j--){
			if (edu(rpts[a], rpts[b]) > edu(rpts[i], sub[j]))
				a = i, b = sub[j].sid;		
		}
		sub[dem++] = pts[i];
	}
}
 
int main(){
	int n; cin >> n;
	for (int i = 0; i < n; i++){
		cin >> pts[i].x >> pts[i].y;
		pts[i].id = i;
	}
 
	sort(pts, pts + n, cmp_x);
	for (int i = 0; i < n; i++) pts[i].sid = i, rpts[i] = pts[i];
	find(0, n - 1);
	
	a = pts[a].id, b = pts[b].id;
	
	cerr << a << " " << b << "\n"; 
	
	if (a > b) swap(a, b);
 
	cout << a << " " << b << " " << setprecision(6) << fixed << sqrt(edu(pts[a], pts[b]));
	return 0;
}