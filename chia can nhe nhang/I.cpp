#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int const D = 300;

struct iii{
	int l, r, id;
} que[N];

int main(){
	int n, m, k; cin >> n >> m >> k;
	int arr[N];
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 1; i <= m; i++){
		cin >> que[i].l >> que[i].r;
		que[i].id = i;
	}

	sort(que + 1, que + m + 1, [](iii a, iii b){
		return make_pair(a.l / D, a.r) < make_pair(b.l / D, b.r);
	});

	int ans = 0;
	int ans_que[N];
	for (int i = 1, l = 1, r = 0; i <= n; i++){
		if (l > que[i].l)
			l--, ans ^= arr[l];
		if (r < que[i].r)
			r++, ans ^= arr[r];
		if (l < que[i].l)
			ans ^= arr[l], l++;
		if (r > que[i].r)
			ans ^= arr[r], r--;
		ans_que[que[i].id] = ans;
	}
	for (int i = 1; i <= m; i++)
		cout << ans_que[i] << "\n";
	return 0;
}