#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;
int const L = 25;

int spt[N][L];
int rgcd(int l, int r){
	int k = log2(r - l + 1);
	return gcd(spt[l][k], spt[r - (1 << k) + 1][k]);
}

typedef long long ll;

map<int, ll> ans;

int n; 
int arr[N];

void emrua(int i, int st){
	if (st == n + 1) return;
	int k = rgcd(i, st);
	int pos = -1;
	for (int l = st, r = n; l <= r;){
		int mid = (l + r) >> 1;
		if (rgcd(i, mid) >= k)	{
			pos = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	ans[k] += (pos - st + 1);
	emrua(i, pos + 1);
}

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	for (int i = 1; i <= n; i++) spt[i][0] = arr[i];
	for (int j = 1; j < L; j++)
		for (int i = 1; i <= n; i++)
			spt[i][j] = gcd(spt[i][j - 1], spt[min(n + 1, i + (1 << (j - 1)))][j - 1]);
		
	for (int i = 1; i <= n; i++){
		emrua(i, i);
	}
	int q; cin >> q;
	while (q--){
		int x; cin >> x;
		cout << ans[x] << "\n";
	}
	return 0;
}