#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;

int main(){
	int n, k; cin >> n >> k;
	int arr[N];
	for (int i = 1; i <= n; i++) cin >> arr[i];

	multiset<int> L, R;
	for (int i = 1; i <= k; i++)
		R.insert(arr[i]);

	while (R.size() > k / 2){
		L.insert(*R.begin());
		R.erase(R.begin());
	}

	for (int i = k + 1; i <= n; i++){
		cout << *L.rbegin() << " ";

		auto a = L.find(arr[i - k]);
		if (a != L.end())
			L.erase(a);
		else{
			auto b = R.find(arr[i - k]);
			if (b != R.end())
				R.erase(b);
		}

		if (L.size() == 0){
			R.insert(arr[i]);
			if (R.size() > k / 2){
				L.insert(*R.begin());
				R.erase(R.begin());
			}
		}
		else if (arr[i] >= *L.rbegin()){
			R.insert(arr[i]);
			if (R.size() > k / 2){
				L.insert(*R.begin());
				R.erase(R.begin());
			}
		}else{
			L.insert(arr[i]);
			if (R.size() < k / 2){
				R.insert(*L.rbegin());
				auto itr = --L.end();
				L.erase(itr);
			}
		}
		// for (auto x: L) cerr << x << " "; cerr << "/ ";
		// for (auto x: R) cerr << x << " "; cerr << "\n";	
		// cout << *L.rbegin() << " ";
	}
	cout << *L.rbegin();
	return 0;
}