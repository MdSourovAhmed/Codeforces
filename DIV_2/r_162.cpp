#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve_A()
{
    int n;
    cin >> n;
    vector<short> v(n+1);
    int a = 0, b;
    for (int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        if (!a && v[i])
            a = i;
        if (v[i])
            b = i;
    }
    int ans = 0;
    for (; b >= a;a++)
        if (!v[a])
            ans++;
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve_A();
}