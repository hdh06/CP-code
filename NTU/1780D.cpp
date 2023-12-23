#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1001
#endif

using namespace std;
#define all(x) x.begin(), x.end()
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define file "TEMPLATE"

typedef long long ll;
typedef pair<int, int> ii;
typedef array<int, 3> iii;
typedef vector<int> vi;
typedef vector<ll> vl;

bool const SINGLE_TEST = 0;

int ask(int x){
	cout << "- " << x << endl;
	int cnt; cin >> cnt;
	return cnt;
}
void answer(int n){
	cout << "! " << n << endl;
}

void solve(){
	int cnt; cin >> cnt;
	int ans = 0, res = 0;
	for (int i = 0; i < 30 && cnt - res > 0;){
		int z = ask(1 << i);
		if (z >= cnt){
			ans += 1 << (i + z - cnt + 1);
			i += z - cnt + 1 + 1;
			res += z - cnt + 1;
			cnt = z;
		}else{
			ans += 1 << i;
			i++;
			cnt = z;
		}
	}
	
	answer(ans);
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	int t;
	if (SINGLE_TEST) t = 1;
	else cin >> t;
	while (t--) solve();
	return 0;
}//it's coding time!