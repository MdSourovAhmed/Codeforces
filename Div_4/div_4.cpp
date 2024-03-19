#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v(1e6);
void solve_E()
{
    int n,k;cin>>n>>k;
    vector<int>v;
    while(n)
    {
        v.push_back((n+1)/2);
        n>>=1;
    }
    int t=0,p=1;
    for(int &i:v)
    {
        if(t<k&&k<=t+i)
        {
            cout<<p*(2*(k-t)-1)<<endl;
            return;
        }
        t+=i;
        p<<=1;
    }
}

void solve_D()
{
    int mx = 1 << 31;
    mx--;
    int n;
    cin >> n;
    map<int, int> m;
    int ans = 0;
    while (n--)
    {
        int a;
        cin >> a;
        if (!m[a])
        {
            ans++;
            m[mx ^ a]++;
        }
        else
            m[a]--;
    }

    cout << ans << endl;
}

void dgt_sm()
{

    for (int j = 1; j < 1e6; ++j)
    {
        int s = 0;
        int i = j;
        while (i)
        {
            s += i % 10;
            i /= 10;
        }
        v[j] = s + v[j - 1];
    }
}

void solve_C()
{
    int n;
    cin >> n;
    cout << v[n] << endl;
}

void solve_B()
{
    int n;
    cin >> n;
    // n++;
    vector<string> v(n);
    int p_i = 0, p_j = 0;
    int done = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        for (int j = 0; j < n; ++j)
            if (!done && v[i][j] == '1')
            {
                p_i = i;
                p_j = j;
                done = 1;
            }
    }
    bool ans = true;
    if (p_i < n - 1 && p_j < n - 1)
    {
        if (v[p_i][p_j + 1] == '1' && v[p_i + 1][p_j] == '1')
            ans = false;
    }
    if (ans)
        cout << "TRIANGLE\n";
    else
        cout << "SQUARE\n";
}

void solve_A()
{
    string s;
    cin >> s;
    vector<int> f(2, 0);
    for (char &c : s)
        f[c - 'A']++;
    if (f[0] > f[1])
        cout << "A\n";
    else
        cout << "B\n";
}

int main()
{
    int t;
    // dgt_sm();
    cin >> t;
    while (t--)
        solve_E();
    // solve_D();
    // solve_C();
    // solve_B();
    // solve_A();
}