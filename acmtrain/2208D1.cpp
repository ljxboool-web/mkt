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
    vector<vector<int>> e(n+1,vector<int>(n+1,0));
    vector<vector<int>> a;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            char x;
            cin>>x;
            e[i][j]=x-'0';
        }
    }
    a=e;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            if(!e[i][j]) continue;
            for(int z=1;z<=n;z++)
            {
                if(z==i||z==j) continue;
                if(!e[j][z]) continue;
                if(!e[i][z])
                {
                    cout<<"NO"<<endl;
                    return;
                } 
            }
        }
    }
    for(int i=1;i<=n;i++) if(!e[i][i]) {cout<<"NO"<<endl;return;}
    for(int p=1;p<=n;p++)
    {
        for(int i=1;i<=n;i++)
        {
            if(i==p) continue;
            if(e[p][i])
            {
                for(int j=1;j<=n;j++)
                {
                    if(i==j||j==p) continue;
                    if(a[p][j]&&a[j][i]) 
                    {
                        e[p][i]=0;
                        break;
                    }
                }
            }
        }
    }
    vector<int> p(n+1,0);
    for(int i=1;i<=n;i++) p[i]=i;
    auto find=[&](auto&& find,int x)->int{
        if(p[x]!=x) p[x]=find(find,p[x]);
        return p[x];
    };
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            if(e[i][j]) sum++,p[find(find,i)]=find(find,j);
        }
    }
    set<int> s;
    for(int i=1;i<=n;i++) s.insert(find(find,i));
    if(s.size()>1||sum!=n-1) {cout<<"NO"<<endl;return;}
    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            if(e[i][j]) cout<<i<<' '<<j<<endl;
        }
    }
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


