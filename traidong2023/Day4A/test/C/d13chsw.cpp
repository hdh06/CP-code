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
#define file "flie"

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

int const N = 105;

int n;
string s, t;

// vi g[2 * N];
// int mtc[2 * N], used[2 * N], timer = 0;
// int w[2 * N][2 * N];
// 
// namespace sub3{
	// bool visit(int v){
		// if (used[v] == timer) return 0;
		// used[v] = timer;
// 		
		// for (auto u: g[v]){
			// if (mtc[u] == -1 || visit(mtc[u])) {
				// mtc[u] = v;
				// return true;
			// }
		// }
		// return false;
	// }
// 	
	// void solve(){
		// cin >> s >> t;
		// n = s.size();
		// s = ' ' + s;
		// t = ' ' + s;
// 		
		// for (int i = 1; i <= 2 * n; i++) g[i].clear();
		// memset(mtc, -1, sizeof mtc);
		// memset(used, 0, sizeof used);
		// timer = 0;
// 		
		// for (int i = 1; i <= n; i++){
			// for (int j = 1; j <= n; j++){
				// int &k = w[i][j + n];
				// if (s[i] == '1' && s[j] == '0') continue;
				// if (s[i] != s[j]) k++;
// 				
// 				
			// }
		// }
	// }
// }
// 

int const sub1Max = 60005;

int dis[sub1Max];

namespace sub1{
	int k(string &s){
		int ans = 0;
		for (int i = 0; i < n; i++){
			ans = ans * 3 + (s[i] == '?'? 2: s[i] - '0');
		}
		return ans;
	}
	void solve(){
		memset(dis, -1, sizeof dis);
		
		// debug(k(t));
		
		queue<string> que;
		que.push(s);
		dis[k(s)] = 0;
		string v, tmp;
		while (!que.empty()){
			v = que.front();
			int idv = k(v);
			que.pop();
			for (int i = 0; i < n; i++){
				for (int c = '0'; c <= '1'; c++){
					if (v[i] == c) continue;
					if (v[i] == '1' && c == '0') continue;
					tmp = v;
					tmp[i] = c;
					int id = k(tmp);
					if (dis[id] == -1){
						dis[id] = dis[idv] + 1;
						que.push(tmp);
					}
				}
			}
			for (int i = 0; i < n; i++)
				for (int j = i + 1; j < n; j++){
					swap(v[i], v[j]);
					int id = k(v);
					if (dis[id] == -1){
						dis[id] = dis[idv] + 1;
						que.push(v);
					}
					swap(v[i], v[j]);
				}
		}
		cout << dis[k(t)] << "\n";
	}
}

namespace sub2{
	bool check(){
		for (int i = 0; i < n; i++) if (s[i] == '?') return false;
		return true;
	}
	void solve(){
		for (int i = 0; i < n; i++) if (s[i] == '?')
			s[i] = '0';
			
		int a = 0, b = 0, c = 0, d = 0;
		for (int i = 0; i < n; i++) if (s[i] != t[i]) {if (s[i] == '0') a++; else c++;}
		for (int i = 0; i < n; i++) if (s[i] != t[i]) {if (t[i] == '0') b++; else d++;}
	
		
		if (a < b){
			cout << -1 << "\n";
		}else{
			int ss = 0, tt = 0;
			for (int i = 0; i < n; i++) if (s[i] != t[i]){
				if (t[i] == '0'){
					ss++;
					a--;
				}else{
					if (c){
						ss++;
						c--;
					}else{
						if (s[i] == '0') tt++;
						else ss++, a--;
					}
				}
			}
			// debug(ss, tt);
			cout << ss / 2 + tt << "\n";
		}
			
	}
}

namespace sub3{
	void solve(){
		int a = 0;
		int b = 0;
		for (int i = 0; i < n; i++) if (s[i] == '0' && t[i] == '1') a++;
		for (int i = 0; i < n; i++) if (s[i] == '1' && t[i] == '0') b++;
		
		int ans = 0;
		// debug(a, b);
		a = min(a, b);
		b = min(a, b); 
		ans = a;
		for (int i = 0; i < n; i++){
			if (s[i] == '0' && t[i] == '1' && a) s[i] = t[i], a--;
			else
			if (s[i] == '1' && t[i] == '0' && b) s[i] = t[i], b--;
		}
		// debug(s);
		// debug(t);
		
		for (int i = 0; i < n; i++) if (s[i] != t[i]){
			if (s[i] == '1'){
				cout << "-1\n";
				return;
			}			
			ans++;
		}
		
		cout << ans << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// #ifdef ONLINE_JUDGE
		// freopen(file".inp", "r", stdin);
		// freopen(file".out", "w", stdout);
	// #endif
	
	int z; cin >> z;
	while (z--){
		cin >> s >> t;
		n = s.size();
		// if (n <= 10)
			// sub1::solve();
		// else if (sub2::check())
			// sub2::solve();
		// else 
			sub3::solve();
	}
	
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!