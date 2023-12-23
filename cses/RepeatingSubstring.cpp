#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

vi sfac(string &s){
	s += '$';
	int n = s.size();
	
	vi p(n), c(n), pn(n), cn(n), cnt(max(256, n));
	
	for (auto x: s) cnt[x]++;
	for (int i = 1; i < 256; i++)
		cnt[i] += cnt[i - 1];
	for (int i = 0; i < n; i++)
		p[--cnt[s[i]]] = i;
	c[p[0]] = 0;
	for (int i = 1; i < n; i++)
		c[p[i]] = c[p[i - 1]] + (s[p[i]] != s[p[i - 1]]);
		
	for (int k = 0; (1 << k) < n; k++){
		for (int i = 0; i < n; i++)
			pn[i] = (p[i] - (1 << k) + n) % n;
		fill(cnt.begin(), cnt.end(), 0);
		for (int i = 0; i < n; i++)
			cnt[c[pn[i]]]++;
		for (int i = 1; i < n; i++)
			cnt[i] += cnt[i - 1];
		for (int i = n - 1; i >= 0; i--)
			p[--cnt[c[pn[i]]]] = pn[i];
		cn[p[0]] = 0;
		for (int i = 1; i < n; i++)
			cn[p[i]] = cn[p[i - 1]]
			+ (ii(c[p[i]], c[(p[i] + (1 << k)) % n])
			!= ii(c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]));
		c.swap(cn);
	}
	s.erase(s.end() - 1);
	p.erase(p.begin());
	return p;
}

int main(){
	string s; cin >> s;
	int n = s.size();
	vi sfa = sfac(s);
	
	vi rank(n);
	for (int i = 0; i < n; i++)
		rank[sfa[i]] = i;

	int k = 0;
	vi lcp(n); int maxp = n - 1;
	for (int i = 0; i < n; i++){
		if (rank[i] == n - 1)
			continue;
		
		int j = sfa[rank[i] + 1];
		while (i + k < n && j + k < n && s[i + k] == s[j + k])
			k++;
		lcp[rank[i]] = k;
		if (lcp[rank[maxp]] < k) maxp = i;
		if (k) k--;
	}
	
	cout << (maxp == n - 1?"-1":s.substr(maxp, lcp[rank[maxp]]));
	return 0;
}