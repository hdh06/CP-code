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
#define file "flie"ß

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

template<typename T> T gcd(T a, T b) { return (b == 0? a : gcd(b, a % b)); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

int const N = 35;

struct PS{
	ll a, b;
	bool hasX = 0;
	PS(){}
	PS(ll a, ll b, bool hasX) :a(a), b(b), hasX(hasX) {}
	
	PS operator +(PS x){
		if (hasX || x.hasX) return PS(0, 0, 1);
		ll nb = lcm(b, x.b);
		ll na = a * nb / b + x.a * nb / x.b;
		ll g = gcd(na, nb);
		if (nb / g < 0) na = -na, nb = -nb;
		return PS(na / g, nb / g, 0);
	}
	PS operator -(PS x){
		if (hasX || x.hasX) return PS(0, 0, 1);
		ll nb = lcm(b, x.b);
		ll na = a * nb / b - x.a * nb / x.b;
		ll g = gcd(na, nb);
		if (nb / g < 0) na = -na, nb = -nb;
		return PS(na / g, nb / g, 0);
	}
	PS operator *(PS x){
		if (hasX || x.hasX) return PS(0, 0, 1);
		ll na = a * x.a;
		ll nb = b * x.b;
		ll g = gcd(na, nb);
		// debug(na, nb, a, b, x.a, x.b);
		if (nb / g < 0) na = -na, nb = -nb;
		return PS(na / g, nb / g, 0);
	}
	PS operator /(PS x){
		if (hasX || x.hasX) return PS(0, 0, 1);
		ll na = a * x.b;
		ll nb = b * x.a;
		ll g = gcd(na, nb);
		if (nb / g < 0) na = -na, nb = -nb;
		return PS(na / g, nb / g, 0);
	}
};

void print(PS z){
	debug(z.a, z.b, z.hasX);
}

int id = 0;

string arr[N];
PS f[N];

vi g[N];

PS ans;

void DFS(int v, PS val){
	debug(arr[v]);
	// print(val);
	if (g[v].size()){
		print(f[g[v][0]]);
		print(f[g[v][1]]);
	}
	if (arr[v] == "X"){
		ans = val;
		return;
	}
	
	if (f[g[v][0]].hasX){
		if (arr[v] == "+")
			DFS(g[v][0], val - f[g[v][1]]);
		if (arr[v] == "-")
			DFS(g[v][0], val + f[g[v][1]]);
		if (arr[v] == "*"){
			if (f[g[v][1]].a == 0 && val.a == 0){
				ans = PS(0, 0, 0);
				return;
			}
			if (f[g[v][1]].a == 0){
				ans = PS(1, 0, 0);
				return;
			}
			DFS(g[v][0], val / f[g[v][1]]);
		}
		if (arr[v] == "/"){
			if (f[g[v][1]].a == 0){
				ans = PS(1, 0, 0);
				return;
			}
			DFS(g[v][0], val * f[g[v][1]]);
		}
	}else{
		if (arr[v] == "+")
			DFS(g[v][1], val - f[g[v][0]]);
		if (arr[v] == "-")
			DFS(g[v][1], f[g[v][0]] - val);
		if (arr[v] == "*"){
			if (f[g[v][0]].a == 0 && val.a == 0){
				ans = PS(0, 0, 0);
				return;
			}
			if (f[g[v][0]].a == 0){
				ans = PS(1, 0, 0);
				return;
			}
			
			DFS(g[v][1], val / f[g[v][0]]);
		}
		if (arr[v] == "/"){
			if (f[g[v][0]].a == 0 && val.a == 0){
				ans = PS(0, 0, 0);
				return;
			}
			if (f[g[v][0]].a == 0 || val.a == 0){
				ans = PS(1, 0, 0);
				return;
			}
			DFS(g[v][1], f[g[v][0]] / val);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// #ifdef ONLINE_JUDGE
		// freopen(file".inp", "r", stdin);
		// freopen(file".out", "w", stdout);
	// #endif
	string s;
	stack<int> st;
	while (cin >> s){
		arr[++id] = s;
		if (s != "+" && s != "-" && s != "*" && s != "/"){
			if (s == "X") f[id] = PS(0, 0, 1);
			else{
				// debug(s);
				 f[id] = PS(stoll(s), 1, 0);
			}
			st.push(id);
		}else{
			int x = st.top(); st.pop(); 
			int y = st.top(); st.pop();
			swap(x, y);
			if (s == "+")
				f[id] = f[x] + f[y];	
			if (s == "-")
				f[id] = f[x] - f[y];
			if (s == "*")
				f[id] = f[x] * f[y];
			if (s == "/"){
				if (!f[y].hasX && f[y].a == 0){
					cout << "none";
					return 0;
				}
				f[id] = f[x] / f[y];
			}
			print(f[id]);
			g[id].pb(x);
			g[id].pb(y);
			// debug(s, arr[x], arr[y]);
			// debug(f[id].a, f[id].b);
			// debug(f[x].a, f[x].b, f[x].hasX);
			// debug(f[y].a, f[y].b, f[y].hasX);
			st.push(id);
		}
	}
	
	debug(f[id].a, f[id].b);
	
	if (!f[id].hasX){
		if (f[id].a == 0) cout << "multiple\n";
		else cout << "none\n";
	}else{
		DFS(id, PS(0, 1, 0));
		debug(ans.a, ans.b);
		if (ans.a == 0 && ans.b == 0) cout << "multiple\n";
		else if (ans.b == 0) cout << "none\n";
		else{ 
			assert(ans.b > 0 && gcd(abs(ans.a), ans.b) == 1);
			cout << ans.a << " " << ans.b << "\n";
		}
	}
	

	return 0;
}//khong phai _HDH, _HDH ko xai template!!!