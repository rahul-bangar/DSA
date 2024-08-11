#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define mod 1000000007
#define ll long long
using namespace std;

void solve()
{
    int x, y, k;
    cin >> x >> y >> k;
    vector<ll> xi(k, 0);
    vector<ll> yi(k, 0);
    for (int i = 0; i < k - 1; i++) xi[i] = yi[i] = i + 1;

    xi[k - 1] = x * k - (k * (k - 1)) / 2;
    yi[k - 1] = y * k - (k * (k - 1)) / 2;

    for (int i = 0; i < k; i++) cout << xi[i] << " " << yi[i] << endl;

}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}