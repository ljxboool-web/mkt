#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
const int INF=1000000000000000010LL;
void solve()
{
    int n;cin>>n;
    vector<vector<int>> a(n+1);
    for(int i=1;i<=n;i++)
    {
        int m;cin>>m;
        vector<int> res;
        unordered_map<int,int> e;
        for(int j=1;j<=m;j++)
        {
            int x;cin>>x;
            res.push_back(x);
        }
        reverse(res.begin(),res.end());
        for(auto t : res)
        {
            if(!e[t]) a[i].push_back(t);
            e[t]=1;
        }
    }
    unordered_map<int,int> mp,vis;
    for(int i=1;i<=n;i++)
    {
        vector<int> mi;
        mi.push_back(1e18+10);
        int chos=-1;
        for(int j=1;j<=n;j++)
        {
            if(vis[j]) continue;
            vector<int> res;
            for(auto t : a[j])
            {
                if(!mp[t]) res.push_back(t);
            }
            if(mi>res)
            {
                chos=j;
                mi=res;
            }
        }
        vis[chos]=1;
        for(auto t : a[chos])
        {
            if(!mp[t]) cout<<t<<' ';
            mp[t]=1;
        }
    }
    cout<<endl;
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
