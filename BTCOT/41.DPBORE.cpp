#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;

	long long dem[N], kq[N];

	int maxn = 0;
	for (int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		maxn = max(maxn, temp);
		dem[temp]+= temp;
	}

	kq[1] = dem[1];
	for (int i = 2; i < maxn + 1; i++){
		kq[i] = max(kq[i-2] + dem[i], kq[i-1]);
	}

	cout << kq[maxn];

	return 0;
}
    