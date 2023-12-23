#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct P{
	int l, r;
	ll sum;
	double ps;
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);

	int n; cin >> n;

	stack<P> hull;

	for (int i = 1; i <= n; i++){
		int x; cin >> x;
		P p = {i, i, x, (double)x};

		while (!hull.empty() && hull.top().ps >= p.ps){
			P curr = hull.top();
			p.l = curr.l;
			p.sum += curr.sum;
			p.ps = p.sum * 1.0 / (p.r - p.l + 1);
			hull.pop();
		}
		hull.push(p);
	}

	vector<double> ans;

	while (!hull.empty()){
		P curr = hull.top();
		for (int i = 1; i <= curr.r - curr.l + 1; i++)
			ans.push_back(curr.ps);
		hull.pop();
	}
	cout << setprecision(10) << fixed;
	reverse(ans.begin(), ans.end());
	for (auto x: ans) cout << x << "\n";
	return 0;
}