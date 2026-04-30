#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
const int INF=1000000000000000010LL;
int getsum(int x)
{
    int sum=0;
    while(x)
    {
        sum+=x%10;
        x/=10;
    }
    return sum;
}
string getstr(int x)
{
    string s="";
    while(x>=10)
    {
        s+=to_string(x);
        x=getsum(x);
    }
    if(x) s+=to_string(x);
    return s;
}
void solve()
{
    string str;cin>>str;
    if(str.size()==1) 
    {
        cout<<str<<endl;
        return;
    }
    int sum=0;
    vector<int> e(10,0);
    for(int i=0;i<str.size();i++) sum+=str[i]-'0',e[(int)(str[i]-'0')]++;
    for(int i=1;i<=sum;i++)
    {
        vector<int> need(10,0),cnt;
        cnt=e; 
        int bitsum=i;
        string s=getstr(i);
        for(auto c : s) bitsum+=c-'0',need[(int)(c-'0')]++;
        if(bitsum!=sum) continue;
        int f=0;
        for(int j=0;j<=9;j++) 
        {
            if(need[j]>e[j]) 
            {
                f=1;
                break;
            }
        }
        if(f) continue;
        for(int j=0;j<=9;j++) cnt[j]-=need[j];
        string front="";
        for(int j=9;j>=0;j--)
        {
            while(cnt[j]>0)
            {
                front+=char('0'+j);
                cnt[j]--;
            }
        }
        front+=s;
        cout<<front<<endl;
        return;
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


