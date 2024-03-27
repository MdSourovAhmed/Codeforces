#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define newl "\n"

void solve_D()
{
    int n,m;cin>>n>>m;
    vector<int>a(n),b(n);
    for(int &i:a)cin>>i;
    for(int &i:b)cin>>i;
}
void solve_C()
{
int n;cin>>n;
string s;cin>>s;
vector<int>pref(n,0);
}

void solve_B()
{
    ll a, b, m;
    cin >> a >> b >> m;
    ll ans = m / a + m / b + 2;
    cout<<ans<<newl;
}

void solve_A()
{
    ll a, b, c;
    cin >> a >> b >> c;
    ll ans = a + b / 3;
    b %= 3;
    c += b;
    if (b && c < 3)
        ans = -1;
    else
        ans += (c + 2) / 3;
    cout << ans << endl;
}

int main()
{
    int t;cin>>t;
    while(t--)
    solve_C();
    // solve_B();
    // solve_A();
}