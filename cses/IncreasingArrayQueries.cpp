#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 5;

typedef long long ll;

int n, q;
int arr[N];

ll ans[N];

ll tree[N << 2], lz[N << 2];
void build(int x = 1, int l = 1, int r = n){
	if (l == r){
		tree[x] = arr[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(2 * x, l, mid);
	build(2 * x + 1, mid + 1, r);
	tree[x] = tree[2 * x] + tree[2 * x + 1];
}
void down(int x, int l, int r){
	if (lz[x] == 0) return;
	int mid = (l + r) >> 1;
	tree[2 * x] = lz[x] * (mid - l + 1);
	tree[2 * x + 1] = lz[x] * (r - mid);
	lz[2 * x] = lz[2 * x + 1] = lz[x];
	lz[x] = 0;
}
void upd(int L, int R, ll val, int x = 1, int l = 1, int r = n){
	if (R < l || r < L) return;
	if (L <= l && r <= R){
		tree[x] = val * (r - l + 1);
		lz[x] = val;
		return;
	}
	down(x, l, r);
	int mid = (l + r) >> 1;
	upd(L, R, val, 2 * x, l, mid);
	upd(L, R, val, 2 * x + 1, mid + 1, r);
	tree[x] = tree[2 * x] + tree[2 * x + 1];
}
ll get(int L, int R, int x = 1, int l = 1, int r = n){
	if (R < l || r < L) return 0;
	if (L <= l && r <= R) return tree[x];
	down(x, l, r);
	int mid = (l + r) >> 1;
	return get(L, R, 2 * x, l, mid) + get(L, R, 2 * x + 1, mid + 1, r);
}

struct que{
	int l, r, id;
	que(){}
	que(int _l, int _r, int _id){l = _l, r = _r, id = _id;}
};

int main(){
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	ll psum[N] = {};
	for (int i = 1; i <= n; i++) psum[i] = psum[i - 1] + arr[i];
	build();

	vector<que> queries;
	for (int i = 1; i <= q; i++){
		int a, b; cin >> a >> b;
		queries.push_back(que(a, b, i));
	}

	sort(queries.begin(), queries.end(), [](que a, que b){
		return a.l > b.l;
	});

	stack<int> st;
	st.push(n + 1);
	arr[n + 1] = INT_MAX;
	int l = n + 1;
	for (auto x: queries){
 		while (l > x.l){
			l--;
			while (arr[l] > arr[st.top()]){
				st.pop();
			}
			upd(l, st.top() - 1, arr[l]);
			st.push(l);
		}
		ans[x.id] = get(x.l, x.r) - (psum[x.r] - psum[x.l - 1]);
	}

	for (int i = 1; i <= q; i++)
		cout << ans[i] << "\n";
	return 0;
}