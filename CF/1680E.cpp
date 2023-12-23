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

void solve(){
	int n; cin >> n;
	string a, b;
	cin >> a >> b;
	int i = 0;
	while (a[i] == '.' && b[i] == '.')
		i++;
		
	int j = n - 1;
	while (a[j] == '.' && b[j] == '.') j--;
	
	vi arr;
	while (i <= j){
		arr.pb(((a[i] == '*') << 1) + (b[i] == '*'));
		i++;
	}
	
	n = sz(arr);
	queue<ii> que;
	vector<vector<int> > dis(n, vi(4, -1));
	dis[0][arr[0]] = 0;
	que.push({0, arr[0]});
	
	while (!que.empty()){
		int v = que.front().st, state = que.front().nd;
		que.pop();
		
		if (state == 3){
			if (dis[v][state ^ 1] == -1){
				dis[v][state ^ 1] = dis[v][state] + 1;
				que.push({v, state ^ 1});
			}
			if (dis[v][state ^ 2] == -1){
				dis[v][state ^ 2] = dis[v][state] + 1;
				que.push({v, state ^ 2});
			}
		}else{ 
			if (dis[v][state ^ 3] == -1){
				dis[v][state ^ 3] = dis[v][state] + 1;
				que.push({v, state ^ 3});
			}
			if (v + 1 < n && dis[v + 1][state | arr[v + 1]] == -1){
				dis[v + 1][state | arr[v + 1]] = dis[v][state] + 1;
				que.push({v + 1, state | arr[v + 1]});
			}
		}
	}
	
	cout << min(dis[n - 1][1], dis[n - 1][2]) << "\n";
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