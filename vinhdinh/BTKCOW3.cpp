#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, arr[16];

int emrua(int i, ll a, ll b, int dem){
	int ans = n;
	if (a == b) ans = n - dem;
	if (i == n + 1) return ans;

	return min({ans, emrua(i + 1, a + arr[i], b, dem + 1), emrua(i + 1, a, b + arr[i], dem + 1), emrua(i + 1, a, b, dem)});
}

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	cout << emrua(1, 0, 0, 0);
	return 0;
}