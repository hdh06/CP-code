#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int N = 1 << 20;

vector<ll> b;
array<ll, 2> a[N];
ll ans[N];
int n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;

    for(int i = 1;i <= (1 << n);i++){
        cin >> a[i][0];
        a[i][1] = i;
    }
    
    sort(a + 1, a + (1 << n) + 1);

    b.push_back(0);
    for(int i = 1;i <= n;i++){
        b.push_back(a[(1 << i)][0]);
    }

    for(int i = 1;i <= (1 << n);i++){
        int k = upper_bound(b.begin() + 1, b.end(), a[i][1]) - b.begin();
        ans[a[i][1]] = k;
    }
    for(int i = 1;i <= (1 << n);i++){
        cout << ans[i] << " ";
    }
    return 0;
}