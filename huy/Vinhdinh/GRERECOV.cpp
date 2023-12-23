#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cout << "k";
	int n;
	cin >> n;
	vector<long long> b((n/2) + 1);
	for (int i = 1; i <= n / 2; i++){
		cout << i;
		cin >> b[i];
		cout << "k" << b[i];
	}
 //    cout << "k";
    long long l = 0;

    vector<long long> a(n + 10);
	// cout << "k";

	 for (int i = 1; i <= n / 2; n++){
		// while (b[i] - l > a[n - (i - 1) + 1] && l <= b[i] - l){
		// 	l++;
		// 	cout << l;
		// }
		a[i] = l;
		// a[n - i + 1] = b[i] - l;
	}

	for (int i = 1; i <= n; i++){
		cout << a[i] << " ";
	}
	return 0;
}