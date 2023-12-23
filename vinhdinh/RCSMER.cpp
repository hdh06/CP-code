#include <bits/stdc++.h>

using namespace std;

string const INF = "123456789987654321";

string mintuche(string a, string b){
	if (a.size() == 0 && b.size() == 0) return string();
	string ans1 = INF, ans2 = INF;

	if (a.size() > 0) ans1 = a[0] + mintuche(a.substr(1, a.size() - 1), b);
	if (b.size() > 0) ans2 = b[0] + mintuche(a, b.substr(1, b.size() - 1));
	if (stoll(ans1) > stoll(ans2))
		return ans2;
	else return ans1;
}

string maxtuche(string a, string b){
	if (a.size() == 0 && b.size() == 0) return string();
	string ans1 = "-1", ans2 = "-1";

	if (a.size() > 0) ans1 = a[0] + maxtuche(a.substr(1, a.size() - 1), b);
	if (b.size() > 0) ans2 = b[0] + maxtuche(a, b.substr(1, b.size() - 1));

	if (ans1 == "-1") return ans2;
	if (ans2 == "-1") return ans1;
	if (stoll(ans1) < stoll(ans2))
		return ans2;
	else return ans1;
}

int main(){
	string a, b;
	cin >> a >> b;
	cout << mintuche(a, b) << "\n" << maxtuche(a, b);
	return 0;
}