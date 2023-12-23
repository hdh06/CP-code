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

int n, m;

struct node{
	node* trie[26];
	int cnt = 0;
};

void insert(node* root, string s){
	node* v = root;
	for (auto x: s){
		if (!v -> trie[x - 'A'])
			v -> trie[x - 'A'] = new node;
		v = v -> trie[x - 'A'];
	}
	v -> cnt++;
} 
int count(node* root, string s){
	node* v = root;
	for (auto x: s){
		if (!v -> trie[x - 'A'])
			return 0;
		v = v -> trie[x - 'A'];
	}
	return v -> cnt;
}

vector<pair<int, string> > z; 

string f;

void DFS(node* v){
	if (v -> cnt) z.pb(mp(v -> cnt, f));
	for (int i = 0; i < 26; i++) if (v -> trie[i]){
		f.pb(i + 'A');
		DFS(v -> trie[i]);
		f.pob();
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// #ifdef ONLINE_JUDGE
		// freopen(file".inp", "r", stdin);
		// freopen(file".out", "w", stdout);
	// #endif
	
	node* root = new node;
	
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		string s; cin >> s;
		int sz = s.size();
		string f;
		for (int a = 0; a < sz; a++){
			f.pb(s[a]);
			insert(root, f);
			f.pob();
		}
		
		for (int a = 0; a < sz; a++){
			f.pb(s[a]);
			for (int b = 0; b < sz; b++) if (a != b){
				f.pb(s[b]);
				insert(root, f);
				f.pob();
			}
			f.pob();
		}
		
		// for (int a = 0; a < sz; a++){
			// f.pb(s[a]);
			// for (int b = 0; b < sz; b++) if (a != b){
				// f.pb(s[b]);
				// for (int c = 0; c < sz; c++) if (c != b && c != a){
					// f.pb(s[c]);
					// insert(root, f);
					// f.pob();
				// }
				// f.pob();
			// }
			// f.pob();
		// }
	}
	
	DFS(root);
	sort(all(z), [](pair<int, string> a, pair<int, string> b){
		if (a.nd.size() == b.nd.size()) return a.st > b.st;
		return a.nd.size() < b.nd.size();
	});
	
	for (int i = 0; i < min((int)z.size(), n); i++)
		cout << z[i].nd << "\n";
	for (int i = 0; i < max(0, n - (int)z.size()); i++)
		cout << "A\n";
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!