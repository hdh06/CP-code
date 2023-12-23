#include <bits/stdc++.h>

using namespace std;

typedef array<int, 2> ii;

int cross(ii A, ii B){
	return A[0] * B[1] - A[1] * B[0];
}

ii vtc(ii A, ii B){return {B[0] - A[0], B[1] - A[1]};}

bool ccw(ii A, ii B, ii C){
	ii AB = vtc(A, B);
	ii BC = vtc(B, C);
	int ans = cross(AB, BC);
	if (ans > 0) return true;
	return false;
}

int main(){
	int n; cin >> n;

	vector<ii> p(n);
	vector<bool> vis(n, 0);

	for (auto &x: p) cin >> x[0] >> x[1];
	sort(p.begin(), p.end());

	deque<int> hull;
	int dem = 0, ans = 0;
	while (dem < p.size()){
		if (dem == p.size() - 1 || dem == p.size() - 2){
			// ans++;
			break;
		}
		int st = hull.size();
		for (int i = 0; i < p.size(); i++) if (!vis[i]){
			while (hull.size() >= 2 + st && ccw(p[hull[hull.size() - 2]], p[hull.back()], p[i]))
				hull.pop_back();
			hull.push_back(i);
		}
		hull.pop_back();

		st = hull.size();
		for (int i = p.size() - 1; i >= 0; i--) if (!vis[i]){
			while (hull.size() >= 2 + st && ccw(p[hull[hull.size() - 2]], p[hull.back()], p[i]))
				hull.pop_back();
			hull.push_back(i);
		}
		hull.pop_back();

		for (auto x: hull){
			dem += (!vis[x]);
			vis[x] = 1;
		}
		ans++;
		hull.clear();
	}

	cout << ans;
	return 0;
}