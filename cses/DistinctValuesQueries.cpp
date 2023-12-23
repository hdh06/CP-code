#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int const D = 400;

int n, q;
int arr[N], ans[N];

struct que{
    int l, r, id;
};
que t[N];

void compress(){
    vector<int> b(arr + 1, arr + n + 1);
    sort(b.begin(), b.end());
    for (int i = 1; i <= n; i++)
        arr[i] = lower_bound(b.begin(), b.end(), arr[i]) - b.begin() + 1;
}

int main(){
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    compress();
    for (int i = 1; i <= q; i++){
        cin >> t[i].l >> t[i].r;
        t[i].id = i;
    }

    sort(t + 1, t + q + 1, [](que a, que b){
        return (make_pair(a.l / D, a.r) < make_pair(b.l / D, b.r));
    });

    int cnt[N] = {};
    int res = 0;

    for (int i = 1, l = 1, r = 0; i <= q; i++){
        while (l > t[i].l){
            l--;
            res += !cnt[arr[l]];
            cnt[arr[l]]++;
        }
        while (r < t[i].r){
            r++;
            res += !cnt[arr[r]];
            cnt[arr[r]]++;
        }
        while (l < t[i].l){
            cnt[arr[l]]--;
            res -= !cnt[arr[l]];
            l++;
        }
        while (r > t[i].r){
            cnt[arr[r]]--;
            res -= !cnt[arr[r]];
            r--;
        }
        ans[t[i].id] = res; 
    }
    
    for (int i = 1; i <= q; i++)
        cout << ans[i] << "\n";
    return 0;
}