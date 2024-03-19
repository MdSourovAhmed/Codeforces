#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int f = 0, l = s.size() - 1;
    while (l > f && s[f] == s[l])
    {
        f++;
        l--;
    }
    if (s[f] <= s[l])
    {
        cout << s << endl;
        return;
    }
    string rev = s;
    reverse(s.begin(), s.end());
    cout << s << rev << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}
