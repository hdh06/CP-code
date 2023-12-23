#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    ll tong = arr[0];
    sort(arr.begin() + 1,arr.end(), greater<int>());
    for(int i = 1; i <= k; i++)
    {
        tong += arr[i];
    }
    for (int i = k + 1; i < n; i++)
    {
        tong -= arr[i];
    }
    cout << tong;
    return 0;
}
    