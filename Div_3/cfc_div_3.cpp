#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve_D()
{
    int n;
    cin >> n;
    char c;
    cin >> c;
    vector<string> v(2 * n);
    map<char, vector<string>> m;
    for (string &s : v)
    {
        cin >> s;
        m[s[1]].push_back(s);
    }

    int T_size = m[c].size(), diff = 0;

    for (auto &a : m)
    {
        if ((a.second.size() & 1) && a.first != c)
        {
            if (T_size)
                T_size--;
            else
                diff++;
        }
        // else diff++;
    }
    vector<string> p;
    // cout<<diff<<" --------------"<<T_size<<"\n\n";
    vector<string> &t_crd = m[c];
    sort(t_crd.begin(), t_crd.end());

    int ind=0;

    if (diff > T_size)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    else
    {
        // cout<<"POSSIBBLE\n";
        for (auto &a : m)
        {
            vector<string> &ans = a.second;
            sort(ans.begin(), ans.end());
            if ((ans.size() & 1) && a.first != c)
            {

                for (string s : ans)
                    p.push_back(s);
                
                p.push_back(t_crd[ind]);
                ind++;
            }
            else if (ans.size() % 2 == 0 && a.first != c)
                for (string s : ans)
                    p.push_back(s);
            
        }
    }
    for (;ind<t_crd.size();++ind)
        p.push_back(t_crd[ind]);
   
    int cnt = 1;
    for (string &s : p)
    {
        cout << s << " ";
        if (cnt % 2 == 0)
            cout << endl;
        cnt++;
    }
}

// void solve_C()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<int> v(n);
//     for (int &i : v)
//     {
//         cin >> i;
//     }
//     string s;
//     cin >> s;
//     int l = 0, r = n - 1;
//     vector<ll>a;
//     for (char c : s)
//     {
//         if ((c == 'L'))
//         {
//             a.push_back(v[l]);
//             l++;
//         }
//         else
//         {
//             a.push_back(v[r]);
//             r--;
//         }
//     }
//     reverse(a.begin(),a.end());
//     ll ml=1;
//     for(int i=0;i<n;++i)
//     {
//         ml*=a[i];
//         ml%=m;
//         v[n-i-1]=ml;
//     }
//     for (int i : v)
//         cout<< i<<" ";
//     cout << endl;
// }
// void solve_B()
// {
//     int n;
//     cin >> n;
//     vector<int> v(n);
//     for (int &i : v)
//         cin >> i;
//     ll ans = v[0];

//     for (int i = 1; i < n; ++i)
//     ans=((ans+v[i])/v[i])*v[i];
//     // for (int i = 1; i < n; ++i)
//     // {
//     //     if (ans < v[i])
//     //         ans = v[i];
//     //     else
//     //     {
//     //         if (ans == v[i])
//     //             ans = 2 * v[i];
//     //         else
//     //         {
//     //             int d = ans + (v[i] - 1);
//     //             d /= v[i];
//     //             if(v[i]==1)d++;
//     //             ans = d * v[i];
//     //         }
//     //     }
//     // }
//     cout << ans << endl;
// }

// void solve_A()
// {
//     int n;
//     cin >> n;
//     ll ans = 0;
//     string s;
//     cin >> s;
//     for (int i = 0; i < n; ++i)
//     {
//         if (s[i] == '@')
//             ans++;
//         else
//         {
//             if (i + 1 < n && s[i] == '*' && s[i] == s[i + 1])
//                 break;
//         }
//     }
//     cout << ans << endl;
// }
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve_D();
        // solve_C();
        // solve_B();
        // solve_A();
    }
}