#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
const int INF=1000000000000000010LL;
void solve()
{
    int n,m;cin>>n>>m;
    vector<int> a(n+1,0),b(m+1,0);
    vector<int> A(n+m+1,0),B(n+m+1,0);
    vector<int> e(n+m+1,0);
    int lcd=1;
    int N=n+m;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        if(lcd<=N)
        {
            lcd=(lcd*a[i])/__gcd(lcd,a[i]);
            if(lcd>N) lcd=1e9+7;
        }
        if(e[a[i]]) continue;
        for(int j=a[i];j<=N;j+=a[i]) e[j]=1;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
        if(e[b[i]]) A[i]=1;
        if(b[i]%lcd!=0) B[i]=1;
    }
    int x2=0,xa=0,xb=0;
    for(int i=1;i<=m;i++)
    {
        if(A[i]&&B[i]) x2++;
        else if(A[i]) xa++;
        else if(B[i]) xb++;
    }
    xa+=(x2+1)/2;
    xb+=(x2)/2;
    if(xa>xb) cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
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
