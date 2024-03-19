#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve_B()
{
    int n;
    cin >> n;
    vector<string> s(n);
    cin >> s[0] >> s[1];
    int rw = 0, cl = 0, pth = 1, paths;
    string ans;
    ans.push_back(s[0][0]);
    while (cl < n - 1)
    {
        if (!rw)
        {
            if (s[0][cl + 1] ^ s[1][cl])
            {
                if (s[0][cl + 1] == '1')
                {
                    rw = 1;          // p1---
                    ans += s[1][cl]; // 0----
                    paths = pth;     // no new paths are possible. so, go to the down row and clm is yet same
                }
                else
                {
                    ans += s[0][cl + 1];
                    cl++;    // p0--
                             // 1---
                    pth = 1; // previous paths are not valied. so, start anew.
                }
            }
            else
            { // p0--/p1--
              // 0---/1--
                ans += s[0][cl + 1];
                cl++;
                pth++; // as long as up and down chars are '=', there is a chance of alternative path
            }
        }
        else
        {
            ans += s[1][cl + 1];
            cl++;
        }
    }
    if (!rw)
    {
        ans += s[1][n - 1]; // if our journey is still on the uupper string,
        paths = pth;        // we never reached the last down char and never got to paths
    }
    cout << ans << "\n"
         << pth << endl;
    // vector<int> v = {0, 1, 2, 1, 2, 3, 1, 2, 3, 2, 1, 2, 2, 2, 3, 1};
    // int n;
    // cin >> n;
    // if (n <= 15)
    // {
    //     cout << v[n] << endl;
    //     return;
    // }
    // int ans = n / 15;
    // n %= 15;
    // if (n >= 5)
    //     ans = min(ans + v[n], ans + 1 + v[n - 5]);
    // else
    //     ans += v[n];
    // cout << ans << endl;
}
// void solve_A()
// {
//     int n;
//     cin >> n;
//     vector<int> v(n);
//     for (int &i : v)
//         cin >> i;
//     sort(v.begin(), v.end());
//     int i, j, k, l;
//     i = v[n - 1];
//     k = v[n - 2];
//     j = v[0];
//     l = v[1];
//     cout << abs(i - j) + abs(j - k) + abs(k - l) + abs(l - i) << endl;
// }

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve_B();
    // solve_A();
}