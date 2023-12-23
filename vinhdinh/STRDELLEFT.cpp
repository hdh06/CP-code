#include <bits/stdc++.h>

using namespace std;

int main(){
	string a, b; cin >> a >> b;

	if (a.size() == b.size() && a.size() == 1){
		if (a[0] == b[0])
			cout << 0;
		else
			cout << 2;
		return 0;
	}
	int dem = 1;
	while (a.size() - dem >= 0 && b.size() - dem >= 0 && a[a.size() - dem] == b[b.size() - dem])
		dem++;	

	dem--;

	cout << a.size() - dem + b.size() - dem;
	return 0;
}