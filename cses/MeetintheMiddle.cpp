#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> SA, SB;
vector<int> A, B;
int n, k;

void emrua(int pos, int sum, vector<int> &arr, vector<ll> &S){
	if (sum > k) return;
	if (pos == arr.size()){
		S.push_back(sum);
		return;
	}

	emrua(pos + 1, sum, arr, S);
	emrua(pos + 1, sum + arr[pos], arr, S);
}

int main(){
	cin >> n >> k;

	for (int i = 1; i <= n; i++){
		int temp; cin >> temp; 
		if (i & 1) A.push_back(temp); 
		else B.push_back(temp);
	}

	emrua(0, 0, A, SA);
	emrua(0, 0, B, SB);

	sort(SA.begin(), SA.end());
	sort(SB.begin(), SB.end());

	ll ans = 0;
	for (auto x: SA){
		int l = lower_bound(SB.begin(), SB.end(), k - x) - SB.begin();
		int r = upper_bound(SB.begin(), SB.end(), k - x) - SB.begin();
		ans += r - l;
	}
	
	cout << ans;

	return 0;
}