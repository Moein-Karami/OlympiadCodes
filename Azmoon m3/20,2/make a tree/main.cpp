#include <bits/stdc++.h>

using namespace std;
int n=1,l;
vector <int> v;
bool b[100000000000];
int mod=10009;
void solve(int x , int y)
{
    if(x==v.size())
        return ;
    if(v[x]==1)
    {
        if(b[2*y+1])
            solve(x+1,2*y+1);
        else
        {
            n++;
            b[2*y+1]=1;
            solve(x+1,1);
        }
    }
    if(v[x]==0)
    {
        if(b[2*y])
            solve(x+1,2*y);
        else
        {
            n++;
            b[2*y]=1;
            solve(x+1,1);
        }
    }
}
void barg(int x)
{
    if(!b[2*x]&&!b[2*x+1])
        l++;
    if(b[2*x])
        barg(2*x);
    if(b[2*x+1])
        barg(2*x+1);
}
int main()
{
    for(int i=1389;i<=2010;i++)
    {
        for(int j=10;j>=0;j--)
        {
            if(i&(1<<j))
                v.push_back(1);
            else
                v.push_back(0);
        }
    }
    b[1]=1;
    solve (0,1);
    barg(1);
    cout<<(((n*l)%mod)*((n*l)%mod))%mod;
    return 0;
}
