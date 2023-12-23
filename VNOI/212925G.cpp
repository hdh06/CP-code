#include <bits/stdc++.h>

using namespace std;

int const N = 3e5 + 1;

#define lb lower_bound
#define all(x) x.begin(), x.end()
#define st first
#define nd second

typedef long long ll;
typedef pair<int, int> ii;

vector<int> dcp[N], tree[N];
void preUpd(int x, int y){
	for (int i = x; i < N; i += i & -i)
		dcp[i].push_back(y);
}
void preGet(int x, int y){
	for (int i = x; i > 0; i -= i & -i)
		dcp[i].push_back(y);
}
void init(){
	for (int i = 0; i < N; i++){
		sort(all(dcp[i]));
		dcp[i].erase(unique(all(dcp[i])), dcp[i].end());
		tree[i].assign(dcp[i].size(), 0);
	}
}
void upd(int x, int y, int val){
	for (int i = x; i < N; i += i & -i)
		for (int j = lb(all(dcp[i]), y) - dcp[i].begin() + 1; j <= dcp[i].size(); j += j & -j)			
			tree[i][j - 1] += val;			
}
ll get(int x, int y){
	ll ans = 0;
	for (int i = x; i > 0; i -= i & -i)
		for (int j = lb(all(dcp[i]), y) - dcp[i].begin() + 1; j > 0; j -= j & -j)
			ans += tree[i][j - 1];	
	return ans;		
}

// x: index, y: value

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	int n; cin >> n;
	int arr[N], tmp[N];
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		preGet(i - 1, N - 1); 
		preGet(i - 1, arr[i]);
		preUpd(i, arr[i]);
		tmp[i] = arr[i];
	}

	int q; cin >> q;

	ii que[N];
	for (int i = 1; i <= q; i++){
		cin >> que[i].st >> que[i].nd;
		int x = que[i].st, y = que[i].nd;
		preGet(x - 1, N - 1);
		preGet(x - 1, tmp[x]);
		preGet(N - 1, tmp[x] - 1);
		preGet(x, tmp[x] - 1);

		preUpd(x, tmp[x]);
		tmp[x] = y;
		preUpd(x, tmp[x]);

		preGet(x - 1, N - 1);
		preGet(x - 1, tmp[x]);
		preGet(N - 1, tmp[x] - 1);
		preGet(x, tmp[x] - 1);
	}

	init();

	ll ans = 0;
	for (int i = 1; i <= n; i++){
		ans += get(i - 1, N - 1) - get(i - 1, arr[i]);
		upd(i, arr[i], 1);
	}

	for (int i = 1; i <= q; i++){
		int x = que[i].st, y = que[i].nd;
		ans -= get(x - 1, N - 1) - get(x - 1, arr[x]);
		ans -= get(N - 1, arr[x] - 1) - get(x, arr[x] - 1);

		upd(x, arr[x], - 1);
		arr[x] = y;
		upd(x, arr[x], 1);

		ans += get(x - 1, N - 1) - get(x - 1, arr[x]);
		ans += get(N - 1, arr[x] - 1) - get(x, arr[x] - 1);
		cout << ans << "\n";
	}
	return 0;
}