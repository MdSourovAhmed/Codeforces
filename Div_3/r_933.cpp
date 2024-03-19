#include <bits/stdc++.h>
#define nw_l cout << "\n"
using namespace std;
typedef long long ll;
const ll N = 1e9 + 7;
void solve_D(){}
// void solve_C(){
//     int n;cin>>n;
//     string s;cin>>s;
//     int ans=0;
//     for(int i=0;i<n-2;)
//     {
//         if(s[i]=='m'||s[i]=='p')
//         {
//             string m="";
//             m+=s[i];
//             m+=s[i+1];
//             m+=s[i+2];
//             if(m=="map"||m=="pie"){i+=2;ans++;}
            
//         }
//         i++;
//     }
//     cout<<ans<<endl;
// }
void solve_B(){
    int n;cin>>n;
    vector<int>v(n);
    for(int &i:v)cin>>i;
    int prv=v[0];
    for(int i=0;i<n-2;++i)
    {
        if(v[i]<0){puts("NO");return;}
        prv=v[i];
        v[i]-=prv;
        v[i+1]-=2*prv;
        v[i+2]-=prv;
    }
    if(v[n-1]!=0||v[n-2]!=0){puts("NO");return;}
    cout<<"YES\n";
}
// void solve_A()
// {
//     int m, n, k;
//     cin >> m >> n >> k;
//     vector<int> a(m), b(n);
//     int ans = 0;
//     for (int &i : a)
//         cin >> i;
//     for (int &i : b)
//     {
//         cin >> i;
//         for (int &j : a)
//             if (i + j <= k)
//                 ans++;
//     }
//     cout<<ans;
//     nw_l;
// }

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        // solve_C();
        solve_B();
        // solve_A();
    }
}
