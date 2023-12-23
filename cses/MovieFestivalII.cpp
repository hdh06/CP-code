#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
#define st first
#define nd second

int main(){
	freopen("inp.inp", "r", stdin);
	freopen("out.out", "w", stdout);
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	int n, k; cin >> n >> k;
	vector<ii> arr(n);
	for (auto &x: arr) cin >> x.st >> x.nd;

	sort(arr.begin(), arr.end(), [](ii a, ii b){
		if (a.nd == b.nd) return a.st < b.st;
		return a.nd < b.nd;
	});

	int cnt = 0;
	multiset<int> s;
	int ans = 0;
	for (auto x: arr){
		if (s.empty()){
			s.insert(x.nd);
			ans++;
		}else{
			auto t = s.upper_bound(x.st);
			if (t != s.begin()){
				s.erase(--t); 
				s.insert(x.nd); 
				ans++;
			}else if (s.size() < k){
				s.insert(x.nd); 
				ans++;
			}
		}
	}
	cout << ans << "\n";
	cerr << (double) clock() / (double) CLOCKS_PER_SEC << "s\n";
	return 0;
}