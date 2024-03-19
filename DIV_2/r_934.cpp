#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve_D() {}
void solve_C() {}
void solve_B()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1, 0), b(n + 1, 0);
    for (int i = 1; i <= 2 * n; ++i)
    {
        int x;
        cin >> x;
        if (i <= n)
            a[x]++;
        else
            b[x]++;
    }

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    vector<int> ans[2];

    int i = 1;
    while (i <= n)
    {
        if (ans[0].size() == 2 * k)
            break;
        if (a[i])
            ans[0].push_back(i);
        if (a[i] > 1)
            ans[0].push_back(i);
        i++;
    }

    i = 1;
    while (i <= n)
    {
        if (ans[1].size() == 2 * k)
            break;
        if (b[i])
            ans[1].push_back(i);
        if (b[i] > 1)
            ans[1].push_back(i);
        i++;
    }
    for (int &j : ans[0])
        cout << j << " ";
    cout << endl;
    for (int &j : ans[1])
        cout << j << " ";
    cout << endl;

    return;
}
// void solve_A()
// {
//     int n, k;
//     cin >> n >> k;
//     cout << (k < n - 1 ? n : 1) << "\n";
// }
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve_B();
    // solve_A();
}