#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
const int INF=1000000000000000010LL;
struct Segtree{
    int n;
    vector<int> tr;
    void init(int n1)
    {
        n=1;
        while(n<n1) n<<=1;
        tr.assign(2*n,0);
        return;
    }
    
    void update(int pos,int x)
    {
        pos=n-1+pos;
        tr[pos]=x;
        pos>>=1;
        while(pos)
        {
            tr[pos]=max(tr[pos<<1],tr[pos<<1|1]);
            pos>>=1;
        }
        return;
    }

    int query(int l,int r)
    {
        l=l+n-1,r=r+n-1;
        int ans=0;
        while(l<=r)
        {
            if(l&1) ans=max(ans,tr[l++]);
            if(!(r&1)) ans=max(ans,tr[r--]);
            l>>=1;
            r>>=1;
        } 
        return ans;
    }
};
int calc(vector<int> a)
{
    int n=a.size()-1;
    vector<int> nxt(n+2,n+1),pre(n+2,0);
    
    deque<int> qu;
    for(int i=1;i<=n;i++) 
    {
        while(qu.size()&&a[i]>a[qu.back()])
        {
            nxt[qu.back()]=i;
            qu.pop_back();
        }
        if(qu.size()) pre[i]=qu.back();
        qu.push_back(i);
    }
    
    Segtree uptree,downtree;
    uptree.init(n);
    downtree.init(n);
    vector<int> down(n+1,1),up(n+1,1),best(n+1,1);
    vector<vector<int>> del(n+2);
    for(int i=1;i<=n;i++)
    {
        if(nxt[i]<=n)
        {
            del[nxt[i]].push_back(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(auto t : del[i]) downtree.update(a[t],0);
        down[i]=downtree.query(a[i]+1,n)+1;
        up[i]=uptree.query(pre[i]+1,i-1)+1;
        best[i]=max(up[i],down[i]);
        downtree.update(a[i],down[i]);
        uptree.update(i,best[i]);
    }
    int pos=-1;
    for(int i=1;i<=n;i++) 
    {
        if(a[i]==n) 
        {
            pos=i;
            break;
        }
    }
    return best[pos];
}
void solve()
{
    int n;cin>>n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans1=calc(a);
    vector<int> b(n+1,0);
    for(int i=1;i<=n;i++)
    {
        b[i]=a[n-i+1];
    }
    int ans2=calc(b);
    int ans=max(ans1,ans2);
    cout<<n-ans<<endl;
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

