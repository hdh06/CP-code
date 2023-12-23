#include <bits/stdc++.h>
using namespace std;
 
map<pair<long long, int>, pair<long long, int>> memo;
pair<long long, int> solve(long long n, int mx) {
    if (n == 0)
        return { 0, 0 };
    if (n < 10) {
        if (n < mx)
            return { 1, n - mx };
        else
            return { 1, 0 };
    }
    if (memo.count({n, mx}))
        return memo[{n, mx}];
 
    long long log10 = 1;
    while (log10 <= n / 10)
        log10 *= 10;
 
    pair<long long, int> curr = { n, mx };
    pair<long long, int> ans = { 0, 0 };
    while (true) {
        int dig = n / log10;
        long long rem = n % log10;
        mx = max(curr.second, dig);
        pair<long long, int> sub = solve(rem, mx);
        ans.first += sub.first;
        n -= rem;
        if (sub.second < 0)
            n += sub.second;
        else {
            n -= mx;
            if (mx > 0)
                ans.first++;
        }
        if (dig == 0)
            break;
    }
    ans.second = n;
    return memo[curr] = ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    long long n;
    cin >> n;
    cout << solve(n, 0).first << "\n";
}