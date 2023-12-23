#include <bits/stdc++.h>

using namespace std;

int const N = 2e6 + 2;
int const A = 177, B = 1e9 + 9;

int p[N];
void init(){
	p[0] = 1;
	for (int i = 1; i < N; i++)
		p[i] = (1LL * p[i - 1] * A) % B;
}

int h[N];

int get(int l, int r){
	return (1LL * h[r] - (1LL * h[l - 1] * p[r - l + 1]) % B + B) % B;
}

int main(){
	init();
	string s; cin >> s;
	s = s + s;
	s = ' ' + s;
	int n = s.size() - 1;
	for (int i = 1; i <= n; i++)
		h[i] = (1LL * h[i - 1] * A % B + s[i]) % B;
	
	n /= 2;
	int k = 1;
	for (int i = 2; i <= n; i++){
		int ans = -1;
		for (int l = 0, r = n - 1; l <= r;){
			int mid = (l + r) >> 1;
			if (get(i, i + mid) == get(k, k + mid))
				l = mid + 1;
			else ans = mid, r = mid - 1;
		}
		
		if (ans != -1 && s[i + ans] < s[k + ans])
			k = i;
	}
	cout << s.substr(k, n);
	return 0;
}