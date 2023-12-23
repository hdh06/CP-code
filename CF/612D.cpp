#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	int n, k; cin >> n >> k;

	vector<pair<int, int> > e;
	for (int i = 1; i <= n; i++){
		int l, r; cin >> l >> r;
		e.push_back({l, 1});
		e.push_back({r + 1, -1});
	}

	sort(e.begin(), e.end());

	vector<pair<int, int> > ans;

	int cnt = 0, last = INT_MIN;
	for (int i = 0; i < 2 * n; i++){
		if (e[i].nd == -1){
			if (cnt - 1 == k - 1){
				ans.push_back({last, e[i].st - 1});
				last = INT_MIN;
			}
			cnt -= 1;
		}else{
			if (last == INT_MIN && cnt + 1 >= k) last = e[i].st;
			cnt++;
		}
		// cout << e[i].st << " " << e[i].nd << "\n";
	}

	cout << ans.size() << "\n";
	for (auto x: ans) cout << x.st << " " << x.nd << "\n";
	return 0;
}