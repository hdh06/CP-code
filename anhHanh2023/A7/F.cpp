#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1606
#endif

using namespace std;
#define all(x) x.begin(), x.end()
#define mp make_pair
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define file "switchsign"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ldb;
typedef string str;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef array<int, 3> iii;
typedef array<ll, 3> lll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;
typedef vector<pll> vll;
typedef vector<bool> vb;
typedef vector<ldb> vd;

int const N = 5e5 + 1;

int sub;
int n, q;
int arr[N];

namespace sub1{
	void solve(){
		while (q--){
			char c; int b; cin >> c >> b;
			if (c == '<')
				for (int i = 1; i <= n; i++) if (arr[i] < b) arr[i] = -arr[i];
			if (c == '>')
				for (int i = 1; i <= n; i++) if (arr[i] > b) arr[i] = -arr[i];
		}
		for (int i = 1; i <= n; i++)
			cout << arr[i] << " ";
	}
}

namespace sub2{
	void solve(){
		priority_queue<ii> que;
		for (int i = 1; i <= n; i++)
			que.push({arr[i], i});
		
		while (q--){
			char c; int b; cin >> c >> b;
			while (!que.empty() && que.top().st > b){
				int k = que.top().nd;
				arr[k] = -arr[k];
				que.pop();
			}
		}
		
		for (int i = 1; i <= n; i++)\
			cout << arr[i] << ' ';
	}
}

namespace sub3{
	int ans[N];
	
	void solve(){
		ii z[N];
		for (int i = 1; i <= n; i++)
			z[i] = mp(arr[i], i);
			
		sort(z + 1, z + n + 1);
		
		int l = 1, r = n;
		for (int j = 1; j <= q; j++){
			int b; cin >> b >> b;
			if (j & 1){
				while (r >= l && z[r].st <= b){
					ans[z[r].nd] = -z[r].st;
					r--;
				}	
			}else{
				while (l <= r && z[l].st <= b){
					ans[z[l].nd] = z[l].st;
					l++;
				}
			}
		}
		
		for (int i = 1; i <= n; i++)
			cout << ans[i] << " ";
		
	}	
}

namespace sub6{
	struct Fw{
		int sum = 0, n = 0;
		vi tree;
		
		Fw(){}
		Fw(int n) :n(n){
			tree.assign(n + 1, 0);
		}
		
		void upd(int x, int val){
			sum += val;
			for (;x < n; x += x & -x) tree[x] -= val;
		}
		int get(int x){
			int ans = sum;
			for (;x > 0; x -= x & -x) ans += tree[x];
			return ans;
		}
	};
	
	int val[N], initSign[N], res[N];
	
	ii pos[N];
	pair<char, int> queries[N];
	
	Fw bit;
	
	void solve(){
		for (int i = 1; i <= n; i++){
			if (arr[i] >= 0) val[i] = x, initSign[i] = +1;
			else val[i] = -x, initSign[i] = -1;
			pos[i] = mp(val[i], i);
		}
		
		sort(pos + 1, pos + n + 1);
		
		for (int j = 1; j <= q; j++)
			cin >> queries[j].st >> queries[j].nd;
			
		int i = n;
		for (int j = q; j >= 1; j--){
			int tmp = abs(queries[j].nd);
			if (queries[j].st == '>' && queries[j].nd < 0) tmp--;
			if (queries[j].st == '<' && queries[j].nd > 0) tmp--;
			
			while (i >= 1 && pos[i].st > tmp){
				int k = pos[i].nd;
				int sign = queries[i].st > 0? -1: +1;
				res[k] = bit.get(i) & 1x ? -sign: sign;
				i--;
			}
			
			if (queries[j].st == '>' && queries[j].nd >= 0) continue;
			if (queries[j].st == '<' && queries[j].nd <= 0) continue;
			
			int k = lb(pos + 1, pos + n + 1, mp(abs(queries[j].nd), 0)) - pos;
			bit.upd(k - 1, 1);
		}
		
		while (i >= 1){
			int k = pos[i].nd;
			res[k]
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef ONLINE_JUDGE
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	#endif

	cin >> sub;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	if (sub == 1)
		sub1::solve();
	if (sub == 2)
		sub2::solve();
	if (sub == 3)
		sub3::solve();

	return 0;
}//khong phai _HDH, _HDH ko xai template!!!


// #include <bits/stdc++.h>
// 
// #ifdef LOCAL
// #include <debug.h>
// #else
// #define debug(...) 1606
// #endif
// 
// using namespace std;
// #define all(x) x.begin(), x.end()
// #define mp make_pair
// #define st first
// #define nd second
// #define lb lower_bound
// #define ub upper_bound
// #define sz(x) (int)x.size()
// #define pb push_back
// #define pob pop_back
// #define pf push_front
// #define pof pop_front
// #define file "switchsign"
// 
// typedef long long ll;
// typedef unsigned long long ull;
// typedef long double ldb;
// typedef string str;
// typedef pair<int, int> ii;
// typedef pair<ll, ll> pll;
// typedef array<int, 3> iii;
// typedef array<ll, 3> lll;
// typedef vector<int> vi;
// typedef vector<ll> vl;
// typedef vector<ii> vii;
// typedef vector<pll> vll;
// typedef vector<bool> vb;
// typedef vector<ldb> vd;
// 
// bool const SINGLE_TEST = 1;
// 
// int const N = 1e5 + 1;
// 
// int n, q;
// ii arr[N];
// 
// bool diff[N];
// 
// void solve(){	
	// int sub; cin >> sub;
	// cin >> n >> q;
	// for (int i = 1; i <= n; i++){
		// cin >> arr[i].st;
		// arr[i].nd = i;
	// }
// 	
	// sort(arr + 1, arr + n + 1);
// 	
	// while (q--){
		// char t; int b;
		// cin >> t >> b;
		// if (t == '>'){
			// int k = ub(arr + 1, arr + n + 1, mp(b, n)) - arr;
			// diff[k] ^= 1;
		// }
		// if (t == '<'){
			// diff[1] ^= 1;
			// int k = lb(arr + 1, arr + n + 1, mp(b, n + 1)) - arr;
			// diff[k] ^= 1;
		// }
	// }
// 	
	// int state = 0;
	// for (int i = 1; i <= n; i++){
		// state ^= diff[i];
		// if (state)
			// arr[i].st = -arr[i].st;
	// }
// 	
	// sort(arr + 1, arr + n + 1, [](ii a, ii b){
		// return a.nd < b.nd;
	// });
// 	
	// for (int i = 1; i <= n; i++)
		// cout << arr[i].st << " ";
// }
// 
// int main(){
	// ios_base::sync_with_stdio(0);//      the
	// cin.tie(0);cout.tie(0);// 	    magical lines	
	// #ifdef ONLINE_JUDGE
		// freopen(file".inp", "r", stdin);
		// freopen(file".out", "w", stdout);
	// #endif
	// int t;
	// if (SINGLE_TEST) t = 1;
	// else cin >> t;
	// while (t--) solve();
	// return 0;
// }//khong phai _HDH, _HDH ko xai template!!!