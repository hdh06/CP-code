#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for (int x = 0; x < t; x++)
    {
    int n, arr[1000001];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (temp < 0) arr[i] = -1;
        else arr[i] = 1;
    }
    int brr[1000001];
    brr[n-1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i]*arr[i + 1] < 0) brr[i] = brr[i+1] + 1;
        else brr[i] = 1;
    }
    for (int i = 0; i < n; i++) cout << brr[i] << " ";
    cout << endl;
    }
    return 0;
}
    