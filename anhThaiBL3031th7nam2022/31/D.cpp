#include <bits/stdc++.h>

using namespace std;

string num[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
string chat[] = {"P", "C", "T", "H"};

map<string, int> crd_id;
map<int, string> crd;
map<int, string> per;
map<string, int> per_id;

void init(){
	int id = 0;
	string p = "01234";
	for (int i = 0; i < 13; i++)
		for (int j = 0; j < 4; j++){
			crd_id[num[i] + chat[j]] = ++id;
			crd[id] = num[i] + chat[j];
		}

	for (int i = 1; i <= 52; i++){
		per[i] = p;
		per_id[p] = i;
		// cout << crd[i] << " " << p << "\n";
		next_permutation(p.begin(), p.end());
	}
}

int main(){
	init();
	int t; cin >> t;
	while (t--){
		string type; cin >> type;
		if (type == "AN"){
			string a; cin >> a;
			vector<string> v(5);
			for (auto &x: v) cin >> x;
			
			sort(v.begin(), v.end(), [](string a, string b){
				return crd_id[a] < crd_id[b];
			});		

			string p = per[crd_id[a]];

			for (int i = 0; i < p.size(); i++)
				cout << v[p[i] - '0'] << " ";
			
			cout << endl;
		}else{
			vector<string> v(5);
			for (auto &x: v) cin >> x;

			vector<int> z(5);
			for (int i = 0; i < 5; i++)
				z[i] = crd_id[v[i]];
			
			string f;

			sort(z.begin(), z.end());

			for (auto &x: v){
				f.push_back((lower_bound(z.begin(), z.end(), crd_id[x]) - z.begin()) + '0');
			}

			cout << crd[per_id[f]] << endl;
		}
	}
	return 0;
}