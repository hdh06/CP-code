#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 2e6 + 1;

bool sang[N] = {1,1};

vector<int> prime;

void caiSang(){
	for (ll i = 2; i < N; i++) if (!sang[i]){
		for (ll j = i*i; j < N; j += i) sang[j] = true;
		prime.push_back(i);
	}
}

int main(){
	caiSang();
	int n;
	cin >> n;
	vector<int> arr(n);

	for (auto &x: arr) cin >> x;	

	sort(arr.begin(), arr.end());

	int t = 0;
	for (int i = 0; i < n; i++){
		if (arr[i] > prime[t]){
			cout << prime[t];
			return 0;
		}
		if (arr[i] == prime[t]) t++;
	}

	cout << "No prime number missing!";
	return 0;
}