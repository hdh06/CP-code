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

int const MAX = 1e9;

vi fibo;
vl sumf;
void init(){
	int a = 1, b = 1, c;
	fibo.pb(1); fibo.pb(1);
	while (1){
		if (a > MAX - b) break;
		c = a + b;
		a = b;
		b = c;
		fibo.pb(c);
	}
	sumf.assign(sz(fibo), 0);
	sumf[0] = 1;
	for (int i = 1; i < sz(fibo); i++)
		sumf[i] = sumf[i - 1] + fibo[i];
}

void solve(){
	int n; cin >> n;
	vi arr(n + 1);
	ll sum = 0;
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		sum += arr[i];
	}
		
	int k = lb(all(sumf), sum) - sumf.begin();
	if (sumf[k] != sum){
		cout << "NO\n";
		return;
	}
	priority_queue<ii> que;
	for (int i = 1; i <= n; i++)
		que.push({arr[i], i});
	
	int last = -1;
	for (int i = k; i >= 0; i--){
		int st = que.top().st, clr = que.top().nd;
		que.pop();
		if (clr == last){
			if (!que.empty() && que.top().st == st){
				ii tmp = {st, clr};
				st = que.top().st, clr = que.top().nd;
				que.pop();
				que.push(tmp);
			}else{
				cout << "NO\n";
				return;
			}
		}
		if (st >= fibo[i]){
			st -= fibo[i];
			que.push({st, clr});
			last = clr;
		}else{
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	init();
	debug(sz(fibo));
	debug(fibo);
	debug(sumf);
	int t;
	if (SINGLE_TEST) t = 1;
	else cin >> t;
	while (t--) solve();
	return 0;
}//it's coding time!