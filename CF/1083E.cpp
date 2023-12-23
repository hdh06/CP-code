#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ldb;

typedef array<ll, 3> iii;

struct line{
	ll a, b;
};

ll val(line d, ll x){
	return d.a*x + d.b;
}

ldb gd(line x, line y){
	return (ldb)(y.b - x.b)/(ldb)(x.a - y.a);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	int n;
	cin >> n;
	vector<iii> rect(n);
	for (auto &x: rect) cin >> x[0] >> x[1] >> x[2];

	sort(rect.begin(), rect.end());

	deque<line> que;
	que.push_front({0, 0});

	ll ans = 0;

	for (auto x: rect){
		while (que.size() >= 2 && val(que.back(), x[1]) <= val(que[que.size() - 2], x[1]))
				que.pop_back();

		ll f = x[0]*x[1] - x[2] + val(que.back(), x[1]);
		ans = max(ans, f);
		line curr = {-x[0], f};
		while (que.size() >= 2 && gd(curr, que[0]) >= gd(que[0], que[1]))
			que.pop_front();
		que.push_front(curr);
	}

	cout << ans;
	return 0;
}