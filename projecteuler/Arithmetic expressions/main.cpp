#include <bits/stdc++.h>
#define int long long int
#define double long double
using namespace std;
bool b[6000];
vector<double> ans;
int len;
vector<double> v;
double s(double x,double y,int tp)
{
    if(tp==1)
        return x*y;
    if(tp==2)
    {
        if(y==0)
            return -6000;
        return x/y;
    }
    if(tp==3)
        return x-y;
    return x+y;
}
void build(int x,double y)
{
    if(x==4)
    {
        int s=y;
        if(s>0)
            b[s]=1;
        return;
    }
    build(x+1,y*v[x]);
    build(x+1,y+v[x]);
    build(x+1,y-v[x]);
    if(v[x]!=0)
        build(x+1,y/v[x]);
    int s=y;
    double t=s;
    if(t!=y&&t<0)
        y=s-1;
    else
        y=s;
    build(x+1,y*v[x]);
    build(x+1,y+v[x]);
    build(x+1,y-v[x]);
    if(v[x]!=0)
        build(x+1,y/v[x]);
}
void solve()
{
    for(int i=0;i<6000;i++)
        b[i]=0;
    do{
        build(1,v[0]);
    }while(next_permutation(v.begin(),v.end()));
    int cnt=1;
    while(b[cnt])
        cnt++;
    cnt--;
    if(cnt>len)
    {
        len=cnt;
        ans.clear();
        for(int i=0;i<4;i++)
            ans.push_back(v[i]);
    }
}
main()
{
    double t=-1.1;
    for(int i=0;i<10;i++)
    {
        for(int j=i+1;j<10;j++)
        {
            for(int k=j+1;k<10;k++)
            {
                for(int l=k+1;l<10;l++)
                {
                    v.clear();
                    v.push_back(i);
                    v.push_back(j);
                    v.push_back(k);
                    v.push_back(l);
                    solve();
                    if(i==1&&j==2&&k==3&&l==4)
                    {
                        cout<<len<<endl;
                    }
                }
            }
        }
    }
    cerr<<len<<endl;
    for(int i=0;i<4;i++)
        cout<<ans[i];
    return 0;
}
