#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int const D = 300;

typedef long long ll;

int n, q;
int arr[N];
ll ans[N];

void compress(int arr[], int n){
	vector<int> b(arr, arr + n);
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());

	for (int i = 0; i < n; i++)
		arr[i] = lower_bound(b.begin(), b.end(), arr[i]) - b.begin() + 1; 
}

int tree[N];
void upd(int k, int val){
	for (int i = k; i < N; i += (i & -i)) tree[i] += val;
}
int get(int k){
	int ans = 0;
	for (int i = k; i > 0; i -= (i & -i)) ans += tree[i];
	return ans;
}

struct que{	
	int l, r, id;
};
que query[N];

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < q; i++){
		cin >> query[i].l >> query[i].r;
		query[i].id = i;
	}

	compress(arr, n);

	sort(query, query + q, [](que a, que b){
		if (a.l / D == b.l / D) return a.r < b.r;
		return a.l / D < b.l / D;
	});

	ll cnt = 0;
	for (int i = 0, l = 0, r = -1; i < q; i++){
		while (l > query[i].l){
			l--;
			upd(arr[l], 1);
			cnt += get(arr[l] - 1);
		}
		while (r < query[i].r - 1){
			r++;
			upd(arr[r], 1);
			cnt += get(n + 1) - get(arr[r]);
		}
		while (l < query[i].l){
			upd(arr[l], -1);
			cnt -= get(arr[l] - 1);
			l++;
		}
		while (r >= query[i].r){
			upd(arr[r], -1);
			cnt -= get(n + 1) - get(arr[r]);
			r--;
		}
		ans[query[i].id] = cnt;
	}

	for (int i = 0; i < q; i++)
		cout << ans[i] << "\n";
	return 0;
}