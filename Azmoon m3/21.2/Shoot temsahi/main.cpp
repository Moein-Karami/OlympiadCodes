#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=10687;
int a[11][11];
void solve(int x,int y,int s)
{
    if(x==10)
        x=1;
    if(y==10)
        y=1;
    if(x==0)
        x=9;
    if(y==0)
        y=9;
    if(s==mod)
        return ;
    if(a[x][y]%4==0)
    {
        a[x][y]++;
        solve(x-1,y,s+1);
    }
    else if(a[x][y]%4==1)
    {
        a[x][y]++;
        solve(x,y+1,s+1);
    }
    else if(a[x][y]%4==2)
    {
        a[x][y]++;
        solve(x+1,y,s+1);
    }
    else if(a[x][y]%4==3)
    {
        a[x][y]++;
        solve(x,y-1,s+1);
    }
}
main()
{
    solve(1,1,1);
    int ans=1;
    int tmp=0;
    for(int i=1;i<=9;i++)
        for(int j=1;j<=9;j++)
            ans=(ans*a[i][j])%mod,tmp+=a[i][j];
    cout<<tmp<<endl<<ans;
    return 0;
}
