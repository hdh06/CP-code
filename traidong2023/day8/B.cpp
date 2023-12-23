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
#define file "syllable"

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


set<char> sy = {'a', 'e', 'u', 'o', 'i'};
set<string> ss = {"au", "oa", "oo", "iou"};

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef ONLINE_JUDGE
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	#endif
	
	string s; cin >> s;
	int ans = 0;
	for (int i = 0; i < s.size(); i++){
		if (sy.find(s[i]) != sy.end()) ans++;
		for (int j = i; j >= max(0, i - 2); j--)
			if (ss.find(s.substr(j, i - j + 1)) != ss.end())
				ans--;
	}
	if (s.back() == 'e') ans--;
	if (s.size() >= 3 && s.substr(s.size() - 2, 2) == "le" && sy.find(s[s.size() - 3]) == sy.end()) ans++;
	ans = max(1, ans);
	cout << ans;
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!