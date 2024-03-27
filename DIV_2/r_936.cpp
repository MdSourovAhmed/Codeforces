// https://codeforces.com/blog/entry/127439
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N=1e5+7;
vector<int>g[N];
int cuts;

int dfs(int nd,int par, int val)
{
    int size=1;
    for(int &cld:g[nd])
    {
        if(cld!=par)
        size+=dfs(cld,nd,val);
    }
    if(size>=val){size=0;cuts++;}
    return size;
}

bool chk(int val,int k)
{
    cuts=0;
    int d=dfs(1,1,val);
    return cuts>k;
}

void solve_C(){
    for(int i=0;i<N;++i)g[i].clear();
    int n,k,eges;cin>>n>>k;
    eges=n-1;
    while(eges--)
    {
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int f=0,e=n,ans=0;
    while(e>=f)
    {
        int mid=(f+e)/2;
        if(chk(mid,k)){ans=mid;f=mid+1;}
        else e=mid-1;
    }
    cout<<ans<<"\n";
}
// void solve_B(){
//     const ll M=1e9+7;
//     int n,k;cin>>n>>k;
//     vector<int>v(n);
//     for(int &i:v)cin>>i;
//     ll c_sm=0,m_sm=0,sm=0;
//     for(int &i:v)
//     {
//         sm+=i;
//         c_sm+=i;
//         if(c_sm<0)c_sm=0;
//         m_sm=max(m_sm,c_sm);
//     }
//     sm=(sm%M+M)%M;  //to handle negative number -n%M=(n%M+M)%M
//     m_sm%=M;

//     for(int i=1;i<=k;++i)
//     {  
//         sm+=m_sm;
//         sm%=M;
//         m_sm=(m_sm*2)%M;
//     }
//     cout<<sm<<endl;
// }

// void solve_A()
// {
//     int n;cin>>n;vector<int>v(n);
//     for(int &i:v)cin>>i;
//     sort(v.begin(),v.end());
//     int ind=(n+1)/2;ind--;
//     int x=v[ind],ans=0;
//     for(int i=ind;i<n;++i)if(v[i]==x)ans++;
//     cout<<ans<<endl;
// }

int main()
{
    int t;cin>>t;
    while(t--)
    solve_C();
    // solve_B();
    // solve_A();
}