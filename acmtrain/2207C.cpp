#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
const int INF=1000000000000000010LL;
void solve()
{
    int n,h;cin>>n>>h;
    int ans=0;
    vector<int> a(n+1,0),e(n+1,0);
    for(int i=1;i<=n;i++) cin>>a[i];
    int mx=0,pos=-1;
    for(int i=1;i<=n;i++)
    {
        int res=h-a[i];
        int L=a[i],R=a[i];
        for(int j=i-1;j>=1;j--) L=max(L,a[j]),res+=max(h-L,0LL);
        for(int j=i+1;j<=n;j++) R=max(R,a[j]),res+=max(h-R,0LL);
        if(mx<=res) mx=res,pos=i;
    }
    ans+=mx;
    int L=a[pos],R=a[pos];
    for(int i=pos;i>=1;i--) L=max(L,a[i]),e[i]=h-L;
    for(int i=pos;i<=n;i++) R=max(R,a[i]),e[i]=h-R;
    mx=0,pos=-1;
    for(int i=1;i<=n;i++) 
    {
        int res=max(h-a[i]-e[i],0LL);
        int L=a[i],R=a[i];
        for(int j=i-1;j>=1;j--) L=max(L,a[j]),res+=max(h-L-e[j],0LL);
        for(int j=i+1;j<=n;j++) R=max(R,a[j]),res+=max(h-R-e[j],0LL);
        if(mx<=res) mx=res,pos=i;
    }
    ans+=mx;
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
