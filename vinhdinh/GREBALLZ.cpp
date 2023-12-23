#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n; cin >> n;
	vector<pair<ll, ll> > arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
		
		
	vector<ll> z;
	for (int i = 1; i < n; i++){
		if (arr[i].st > arr[0].st)
			z.push_back(arr[i].nd - arr[i].st + 1);
	}	
	
	sort(z.begin(), z.end());
	
		
	return 0;
}