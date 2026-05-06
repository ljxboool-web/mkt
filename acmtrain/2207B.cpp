#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
const int INF=1000000000000000010LL;
void solve()
{
    int n,m,l;cin>>n>>m>>l;
    vector<int> e(l+1,0);
    for(int i=1;i<=n;i++) 
    {
        int x;cin>>x;
        e[x]=1;
    }
    int M=min(n+1,m);
    vector<int> b(M+1,0),vis(M+1,0);
    int cnt=0,pos=0;
    for(int i=1;i<=l;i++)
    {
        int mi=1e18+10,p1=-1;
        for(int j=0;j<M;j++)
        {
            if(vis[j]) continue;
            if(mi>b[j]) mi=b[j],p1=j;
        }
        b[p1]++;
        if(e[i])
        {
            cnt++;
            int mx=-1e18+10,p2=-1;
            for(int j=0;j<M;j++)
            {
                if(vis[j]) continue;
                if(mx<b[j]) mx=b[j],p2=j;
            }
            b[p2]=0;
            if(M-n-1+cnt>0) vis[p2]=1;
        }
    }
    int ans=0;
    for(int i=0;i<M;i++) ans=max(ans,b[i]);
    cout<<ans<<endl;
    return;
}
signed main()
{
    IOS;
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}


