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
#define file "fiel"

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

int const N = 2e5 + 1;

int n;
ll arr[N];

namespace sub1{
	void solve(){
		ll ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				for (int k = j + 1; k <= n; k++)
					if ((arr[i] ^ arr[j]) < (arr[j] ^ arr[k]))
						ans++;
		cout << ans << "\n";
	}
}
namespace sub2{
	int const L = 31;
	struct node{
		node* trie[2] = {};
		ll cnt = 0;
	};
	
	void insert(node* v, ll x){
		// debug(i, x);
		v -> cnt++;
		for (int i = L - 1; i >= 0; i--){
			int bit = !!(x & (1LL << i));
			if (!v -> trie[bit]) v -> trie[bit] = new node;
			v = v -> trie[bit];
			v -> cnt++;
		}
	}
	void erase(node* v, ll x){
		// debug(i, x);
		v -> cnt--;
		for (int i = L - 1; i >= 0; i--){
			int bit = !!(x & (1LL << i));
			v = v -> trie[bit];
			v -> cnt--;
		}
	}
	
	ll get(node* v, ll x, ll y){
		// debug(x);
		ll ans = 0;
		for (int i = L - 1; i >= 0; i--){
			int a = !!(x & (1LL << i));
			int b = !!(y & (1LL << i));
			int bit = a ^ b;
			// if (x == 0 && y == 2) debug(i, a, b);		
			if (bit == 0 && v -> trie[!b]) ans += v -> trie[!b] -> cnt;
			// debug(i, bit);
			if (!v -> trie[a]) break;// v -> trie[bit] = new node;
			v = v -> trie[a];
		}
		return ans;
	}
	
	void reset(node* v){
		v -> cnt = 0;
		if (v -> trie[0]) reset(v -> trie[0]);
		if (v -> trie[1]) reset(v -> trie[1]);
	}
	
	void solve(){
		ll ans = 0;
		node* root = new node;
		for (int i = 1; i <= n; i++){
			// reset(root);
			for (int j = n; j > i; j--){
				ans += get(root, arr[i], arr[j]);
				// debug(i, j, arr[i] ^ arr[j]);
				// debug(get(root, arr[i], arr[j]));
				insert(root, arr[j]);
			}
			for (int j = i + 1; j <= n; j++)
				erase(root, arr[j]);

		}
		cout << ans << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	
	// if (n <= 100)
		// sub1::solve();
	// else if (n <= 3000)
		sub2::solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!