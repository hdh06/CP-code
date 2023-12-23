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

bool const SINGLE_TEST = 1;

bool ask(int l, int r){
	cout << "? " << l << " " << r << "\n";
	cout.flush();
	bool ans; cin >> ans;
	return ans;
}

void answer(string s){
	cout << "!" << s << "\n";
	cout.flush();
}

void solve(){
	cout << "? 1 2\n"; cout.flush();
	int n, q; cin >> n >> q;
	bool d; cin >> d;
	
	string s(n + 1, ' ');
	stack<int> st;
	for (int i = 1; i <= n; i++){
		if (i == 2){
			if (d){
				s[1] = '(';
				s[2] = ')';
				st.pop();
			}else st.push(2);
			continue;
		}
		if (!st.empty() && ask(st.top(), i)){
			s[st.top()] = '(';
			s[i] = ')';
			st.pop();
		}else st.push(i);
	}
	
	int z = st.size() / 2;
	while (!st.empty()){
		if (st.size() <= z) s[st.top()] = ')';
		else s[st.top()] = '(';
		st.pop();
	}
	// for (int i = 1; i <= n / 2; i++)
		// s[i] = '(';
	// for (int i = n / 2 + 1; i <= n; i++)
		// s[i] = ')';
	answer(s);
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
