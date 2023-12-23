#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	ll p[10000000] = {}, id = 0;
	for (int mask = 0; mask < (1 << 10); mask++){
		vector<int> z;
		for (int i = 0; i <= 9; i++) if (mask & (1 << i))
			z.push_back(i);
			
		sort(z.begin(), z.end());
		do{
			if (z.size() && z[0] == 0) continue;
			ll d = 0;
			for (auto x: z) d = d * 10 + x;
			p[id++] = d;
		}while (next_permutation(z.begin(), z.end()));
	}
	
	sort(p, p + id);
	
	int t; cin >> t;
	while (t--){
		ll L, R; cin >> L >> R;
		int r = upper_bound(p, p + id, R) - p - 1;
		int l = lower_bound(p, p + id, L) - p - 1;
		cout << r - l << "\n";
	}
	return 0;
}