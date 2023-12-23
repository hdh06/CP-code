#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> p(n), a(m);
	for (int i = 0; i < n; i++){
		cin >> p[i];
	}
	for (int i = 0; i < m; i++){
		cin >> a[i];
	}

	sort(a.begin(),a.end());
	sort(p.begin(),p.end());

	int j = 0, i = 0, dem = 0;
	for (; i < n && j < m;){
		if (a[j] - k <= p[i] && p[i] <= a[j] + k){
			i++;
			j++;
			dem ++;
		}
		else if (p[i] < a[j] - k) i++;
		else if (p[i] > a[j] + k) j++;
	}

	cout << dem;
	return 0;
}