//cses.fi/problemset/task/2194 
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct pt{
	ll x, y;
};

int const N = 2e5;

pt pts[N];
ll D = LLONG_MAX;

bool cmp_x(pt a, pt b){return a.x < b.x;}
bool cmp_y(pt a, pt b){return a.y < b.y;}

ll edu(pt a, pt b){
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

void find(int l, int r){
	if (r <= l) return;

	if (l + 1 == r){
		D = min(D, edu(pts[l], pts[r]));
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
	for (int i = l; i <= r; i++) if (abs(pts[i].x - midx) < D){
		for (int j = dem - 1; j >= 0 && pts[i].y - sub[j].y < D; j--)
			D = min(D, edu(pts[i], sub[j]));
		sub[dem++] = pts[i];
	}
}

int main(){
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> pts[i].x >> pts[i].y;

	sort(pts, pts + n, cmp_x);
	find(0, n - 1);

	cout << D;
	return 0;
}