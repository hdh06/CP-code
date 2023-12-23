#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;

int n;
int a[N], b[N];

void compress(int a[]){
	vector<int> b(a + 1, a + n + 1);
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	for (int i = 1; i <= n; i++)
		a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
}

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
		sort(dcp[i].begin(), dcp[i].end());
		tree[i].resize(dcp[i].size());
	}
}
void upd(int x, int y, int val){
	for (int i = x; i < N; i += i & -i)
		for (int j = lower_bound(dcp[i].begin(), dcp[i].end(), y) - dcp[i].begin() + 1; j <= dcp[i].size(); j += j & -j)
			tree[i][j - 1] = max(tree[i][j - 1], val);
}
int get(int x, int y){
	int ans = 0;
	for (int i = x; i > 0; i -= i & -i) 
		for (int j = lower_bound(dcp[i].begin(), dcp[i].end(), y) - dcp[i].begin() + 1; j > 0; j -= j & -j)
			ans = max(tree[i][j - 1], ans);	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> b[i];

	compress(a); compress(b);

	for (int i = 1; i <= n; i++){
		preGet(a[i] - 1, b[i] - 1);
		preUpd(a[i], b[i]);
	}
	preGet(N - 1, N - 1);

	init();

	for (int i = 1; i <= n; i++)
		upd(a[i], b[i], get(a[i] - 1, b[i] - 1) + 1);
	
	cout << get(N - 1, N - 1);
	return 0;
}