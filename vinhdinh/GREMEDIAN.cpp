#include <bits/stdc++.h>

using namespace std;

int const N = 501;

int main(){
	int n, x; cin >> n >> x;
	int arr[N];
	
	int a = 0, b = 0, c = 0;
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		if (arr[i] < x) a++;
		if (arr[i] == x) b++;
		if (arr[i] > x) c++;
	}
	
	while (b > 1 && a < c - 1) a++, b--;
	while (b > 1 && c < a) c++, b--;
	
	if (a == c) cout << !b << "\n";
	else cout << !b + (a > c? a - c: (c - 1) - a);
	return 0;
}