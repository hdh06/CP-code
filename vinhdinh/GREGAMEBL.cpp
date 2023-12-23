#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;

int main(){
	int n; cin >> n;
	int a[N], b[N];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
		
	sort(1 + a, a + n + 1);
	sort(1 + b, b + n + 1);
	
	int sum_a = 0, sum_b = 0;
	for (int i = n, j = n; i >= 1 || j >= 1;){
		if (b[j] > a[i]) j--;
		else sum_a += a[i], i = max(0, i - 1);
		if (a[i] > b[j]) i--;
		else sum_b += b[j], j = max(0, j - 1);
	}
	
	cout << sum_a - sum_b;	
	return 0;
}