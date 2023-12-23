#include <bits/stdc++.h>

using namespace std;

vector<int> sfac(string &s){
	s = s + '$';
	int n = s.size();
	int alpha = 256;
	vector<int> p(n), c(n), cnt(max(n, alpha));

	// init for 2^0
	for (auto x: s) cnt[x]++;
	for (int i = 1; i < alpha; i++)
		cnt[i] += cnt[i - 1];
	for (int i = 0; i < n; i++)
		p[--cnt[s[i]]] = i;
	c[p[0]] = 0;
	int cls = 0;
	for (int i = 1; i < n; i++){
		if (s[p[i]] != s[p[i - 1]]) cls++;
		c[p[i]] = cls;
	}

	//calculate for 2^k (k <= log2(n))
	vector<int> pn(n), cn(n);
	for (int k = 0; (1 << k) < n; k++){
		//sort by second part
		for (int i = 0; i < n; i++)
			pn[i] = (p[i] - (1 << k) + n) % n;

		//counting sort
		fill(cnt.begin(), cnt.begin() + cls + 1, 0);
		for (int i = 0; i < n; i++)
			cnt[c[pn[i]]]++;
		for (int i = 1; i <= cls; i++)
			cnt[i] += cnt[i - 1];
		for (int i = n - 1; i >= 0; i--)
			p[--cnt[c[pn[i]]]] = pn[i];

		// recalc class
		cn[p[0]] = 0;
		cls = 0;
		for (int i = 1; i < n; i++){
			if (make_pair(c[p[i    ]], c[(p[i    ] + (1 << k)) % n])
			!=  make_pair(c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]))
				cls++;
			cn[p[i]] = cls;
		}	
		c.swap(cn);
	}
	// p.erase(p.begin());
	// s.erase(s.end() - 1);
	return p;
}

int main(){
	string s;
	cin >> s;

	vector<int> sfa = sfac(s);
	// for (auto x: sfa)
		// cout << x << " ";
	// for (int i = 1; i < sfa.size(); i++)
		// if (sfa[i] + 1 != sfa[i - 1]){
			// cout << i << "\n";
			// break;
		// }
		
	for (int i = 0; i < s.size(); i++)
		if (s[i] == 'b') cout << i << " ";
	return 0;
}