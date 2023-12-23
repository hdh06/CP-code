#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
#define all(x) x.begin(), x.end()

vi sfac(string s){
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
		fill(all(cnt), 0);
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
	return vi(1 + all(p));
}

int main(){
	string s; cin >> s;
	long long k; cin >> k;
	vi sfa = sfac(s);
	int n = s.size();
	
	vi rank(n);
	for (int i = 0; i < n; i++)
		rank[sfa[i]] = i;
	
	vi lcp(n - 1);
	int z = 0;	
	for (int i = 0; i < n; i++){
		if (rank[i] == n - 1) continue;
		int j = sfa[rank[i] + 1];
		while (i + z < n && j + z < n && s[i + z] == s[j + z])
			z++;
		lcp[rank[i]] = z;
		if (z) z--;	
	}
	
	string ans;
	for (int i = 0, pre = 0; i < n; i++){
		if (k >= n - sfa[i] - pre){
			k -= n - sfa[i] - pre;
		}else{
			cout << s.substr(sfa[i], pre + k);
			return 0;
		}
		pre = lcp[i];
	}
		
	return 0;
}