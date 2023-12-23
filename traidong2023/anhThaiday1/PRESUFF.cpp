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

int const N = 1e5 + 1;

struct node{
	node* trie[26];
	bool isEnd;
	// node (){}
};

node* newNode(){
	node* v = new node;
	for (int i = 0; i < 26; i++) v -> trie[i] = nullptr;
	v -> isEnd = 0;
	return v;
}

node* rt;

set<string> ms;

void insert(node* rt, string s){
	// ms.insert(s);
	debug(s);
	node* v = rt;
	for (auto x: s){
		if (!v -> trie[x - 'a'])
			v -> trie[x - 'a'] = newNode();
		v = v -> trie[x - 'a'];
	}
	v -> isEnd = 1;
}

bool find(node* rt, string s){
	node* v = rt;
	for (auto x: s){
		if (!v -> trie[x - 'a'])
			return false;
		v = v -> trie[x - 'a'];
	}
	return v -> isEnd;
}
int cnt[N];
bool only1Suf[N];

ll ans = 0;

string f;
vector<string> g[26];
vector<string> zzz;


void calc(node* v){
	if (v -> isEnd){
		 ans++;
		 // zzz.pb(f);
	}
	// ans++;
	bool z = 1;
	for (int i = 0; i < 26; i++){
		if (!v -> trie[i])	{
			// debug(f, string(1, i + 'a'), cnt[i]);
			// for (auto x: g[i])
				// zzz.pb(f + x);
// 			
			ans += cnt[i];
		}else {
			z = 0;
			if (!v -> trie[i] -> isEnd && only1Suf[i]){
				debug(".");
				ans++;
			}
			// if (v -> trie[i] -> isEnd) ans++;
			// f.pb(i + 'a');
		
			calc(v -> trie[i]);
			// f.pob();
		}
	}
}


int n;

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// #ifdef ONLINE_JUDGE
		// freopen(file".inp", "r", stdin);
		// freopen(file".out", "w", stdout);
	// #endif
// 	
	cin >> n;
	vector<string> z, arr;
	
	node* rt = newNode();
	// rt -> isEnd;
	vector<string> ms;
	for (int i = 1; i <= n; i++){
		string s; cin >> s;
		arr.pb(s);
		for (int j = 0; j < s.size(); j++)
			ms.pb(s.substr(j, s.size() - j));
		// if (s.size() == 1) only1Suf[s[0] - 'a'] = 1;
		insert(rt, s);
	}
	
	sort(all(ms));
	ms.erase(unique(all(ms)), ms.end());
	for (auto x: ms){
		cnt[x[0] - 'a']++;
		g[x[0] - 'a'].pb(x);
		if (x.size() == 1) only1Suf[x[0] - 'a'] = 1;
	}
	
	
	for (int i = 0; i < 26; i++) if (rt -> trie[i]){
		// f.pb(i + 'a');
		// if (!rt -> trie[i] -> isEnd && only1Suf[i]) ans++;
		calc(rt -> trie[i]);
		// f.pob();
	}
	
	debug(zzz);
	
	// for (int i = 0; i < 26; i++) if (only1Suf[i])
		// cerr << i << "\n";
		// ans--;
		
	cout << ans;
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!