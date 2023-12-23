#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> arr(n + 1), f(n + 1), d(n + 1);
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		f[i] = 1;
		d[i] = 0;
		for (int j = 1; j < i; j++){
			if (arr[j] < arr[i])
				if (f[j] + 1 > f[i]){
					f[i] = f[j] + 1;
					d[i] = j;
				}
		}
	}

	int maxn = 0;
	for (int i = 1; i <= n; i++){
		if (f[i] > f[maxn]){
			maxn = i;
		}
	}

	cout << f[maxn] << endl;

	vector<int> q;

	while (maxn != 0){
		q.push_back(maxn);
		maxn = d[maxn];
	}

	reverse(q.begin(), q.end());

	for (auto i: q){
		cout << i << " ";
	}
	return 0;
}