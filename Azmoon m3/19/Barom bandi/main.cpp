#include <bits/stdc++.h>

using namespace std;
int a[7];
int ans;
bool b[101];
void clean()
{
    for(int i=0;i<=100;i++)
        b[i]=0;
}
int mask()
{
    clean();
    for(int i=0;i<64;i++)
    {
        int t=0;
        for(int j=0;j<=5;j++)
        {
            if(i&(1<<j))
                t+=a[j];
        }
        b[t]=1;
    }
    int ret=0;
    for(int i=0;i<=100;i++)
        if(b[i])
        ret++;
    return ret;
}
void solve(int x,int y)
{
    if(x==5)
    {
        int t=0;
        for(int i=0;i<=5;i++)
            t+=a[i];
        if(t==100)
            ans=max(ans,mask());
        return;
    }
    x++;
    for(int i=y;i<=25;i++)
    {
        a[x]=i;
        solve(x,i);
    }
}
int main()
{
    for(int i=10;i<=25;i++)
    {
        a[0]=i;
        solve(0,i);

    }
    cout<<(ans*ans*ans)%10099;
    return 0;
}
