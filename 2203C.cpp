#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
const int INF = 1000000000000000010LL;
void solve()
{
    int s,m;cin>>s>>m;
    vector<int> g;
    int res=m,cnt=0;
    while(res)
    {
        if(res&1) g.push_back((1LL<<cnt));
        cnt++;
        res/=2;
    }
    reverse(g.begin(),g.end());
    int ans=0;
    int l=1,r=INF;
    auto check=[&](int cnt)->int{
        int sum=s;
        for(auto t : g)
        {
            int num=min(cnt,sum/t);
            sum-=num*t;
        }   
        if(sum>0) return 0;
        else return 1;
    };

    while(l<r)
    {
        int mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    if(l!=INF) cout<<l<<endl;
    else cout<<-1<<endl;
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
