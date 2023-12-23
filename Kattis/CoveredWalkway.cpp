#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ldb;

struct line{
	ll a, b;
};

ll val(line d, ll x){
	return d.a*x + d.b;
}

bool sgd(line d1, line d2, line d3, line d4){
	ll t1 = (d1.b - d2.b);
	ll m1 = (d2.a - d1.a);
	ll t2 = (d3.b - d4.b);
	ll m2 = (d4.a - d3.a);
	return (t1*m2 <= t2*m1);
}

int main(){
	int n; ll c;		
	cin >> n >> c;
	vector<ll> arr(n);

	for (auto &x: arr) cin >> x;

	deque<line> que;
	
	que.push_back({0, 0});

	vector<ll> dp(n + 1, 0);

	for (int i = 1; i < n; i++){
		ll x = arr[i - 1];
		while (que.size() >= 2 && val(que[0], x) >= val(que[1], x)){
			cout << "pop " << que[0].a << "x + " << que[0].b << endl;
			que.pop_front();

		}

		dp[i] = x*x + c + val(que.back(), x);
		cout << "using " << que[0].a << "x + " << que[0].b << endl;

		// cout << arr[i] << "->" << que[0].a/(-2) << endl;

		line curr = {-2*x, dp[i - 1] + x*x};

		// if (i == 3) cout << (que.size() >= 2) << "&&" << "sgd([" << que.back().a << "x + " << que.back().b << "],[" << curr.a << "x + " << curr.b << "],[" << que.back().a << "x + " << que.back().b << "],[" << que[que.size() - 2].a << "x + " << que[que.size() - 2].b << "])";

		while (que.size() >= 2 && sgd(curr, que.back(), que.back(), que[que.size() - 2])){
			cout << "pop " << que.back().a << "x + " << que.back().b << endl;
			que.pop_back();
		}

		que.push_back(curr);
		cout << "push " << curr.a << "x + " << curr.b << "\n";
		cout << "left: ";
		for (auto t: que) cout << "[" << t.a << "x + " << t.b << "] ";
		cout << endl;
	}

	cout << sgd({-90, 7509}, {-46, 5530}, {-46, 5530}, {-2, 1});

	// for (int i = 0; i < n; i++) 
	// 	cout << arr[i] << " \n"[i == n - 1];
	// for (int i = 0; i <= n; i++) 
	// 	cout << dp[i] << " \n"[i == n];

	// cout << dp[n - 1];
	return 0;
}