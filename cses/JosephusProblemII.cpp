#include <bits/stdc++.h>
 
using namespace std;
 
int const N = 2e5 + 1;
int const LOGN = log2(N);
 
int tree[N];
void upd(int k, int val){
    for (int i = k; i < N; i += (i & -i))
        tree[i] += val;
}
int get(int k){
    int ans = 0;
    for (int i = k; i > 0; i -= (i & -i))
        ans += tree[i];
    return ans;
}
int bis(int val){
    int sum = 0;
    int pos = 0;
    for (int i = LOGN; i >= 0; i--)
        if (pos + (1 << i) < N && sum + tree[pos + (1 << i)] < val){
            pos += 1 << i;
            sum += tree[pos];
        }
    return pos + 1;
}
 
int main(){
    int n, k; cin >> n >> k;
 
    for (int i = 1; i <= n; i++)
        upd(i, 1);
 
    int p = k % n;
    while (n--){
        int z = bis(p + 1);
        cout << z << " ";
        upd(z, -1);
        if (n != 0) p = (p % n + k) % n;
    }
    return 0;
}