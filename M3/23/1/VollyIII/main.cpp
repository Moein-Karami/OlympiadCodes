#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int mod=10357;
vector <int> v[2];
int x;
int ans;
int f[10];
int c[7][7];
void check()
{
    for(int i=0;i<7;i++)
        for(int j=0;j<7;j++)
            c[i][j]=0;
    int maxi[2]={0,0};
    for(int i=0;i<2;i++)
        for(int j=0;j<5;j++)
            maxi[i]=max(maxi[i],v[i][j]);
    if(maxi[0]<2||maxi[1]<2)
        return ;
    vector<int> t[2];
    for(int i=0;i<2;i++)
        for(int j=0;j<5;j++)
            t[i].push_back(v[i][j]);
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
            if(t[1][j]>3)
                c[i][j]=min(2LL,t[0][i]),t[1][j]-=min(2LL,t[0][i]);
        for(int j=0;j<5;j++)
            if(t[1][j]>2&&c[i][j]<2)
                c[i][j]+=min(1LL,t[0][i]),t[1][j]-=min(1LL,t[0][i]);
        for(int j=0;j<5;j++)
            if(t[1][j]>1&&c[i][j]<2)
                c[i][j]+=min(1LL,t[0][i]),t[1][j]-=min(1LL,t[0][i]);
        for(int j=0;j<5;j++)
            if(t[1][j]&&c[i][j]<2)
                c[i][j]+=min(1LL,t[0][i]),t[1][j]-=min(1LL,t[0][i]);
        for(int j=0;j<5;j++)
            t[0][i]-=c[i][j];
        if(t[0][i])
            return;
    }
    int b=f[5]*f[5];
    int a[12];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<=10;j++)
            a[j]=0;
        for(int j=0;j<5;j++)
            a[v[i][j]]++;
        for(int j=0;j<=10;j++)
                b/=f[a[j]];
    }
    ans+=b;
    return;
}
void build(int rem,int id,int last)
{
    if(v[id].size()==5)
    {
        if(id==0)
            build(x,1,x);
        else
            check();
        return ;
    }
    for(int i=0;i<=min(last,rem);i++)
    {
        v[id].push_back(i);
        build(rem-i,id,i);
        v[id].pop_back();
    }
}
main()
{
    f[0]=1;
    for(int i=1;i<10;i++)
        f[i]=i*f[i-1];
    for(x=2;x<=10;x++)
        build(x,0,x);
    cout<<ans<<"  "<<ans%mod;
    return 0;
}
