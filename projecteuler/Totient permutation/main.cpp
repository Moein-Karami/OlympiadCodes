#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=1e7+1,inf=1e9;
bool b[maxn];
int phi[maxn];
int dig[10][10];
main()
{
    for(int i=1;i<maxn;i++)
        phi[i]=i;
    for(int i=2;i<maxn;i++)
    {
        if(!b[i])
        {
            for(int j=i;j<maxn;j+=i)
            {
                b[j]=1;
                phi[j]/=i;
                phi[j]*=i-1;
            }
        }
    }
    /*int ans=0;
    for(int i=2;i<=1000000;i++)
        ans+=phi[i];
    cout<<ans<<endl;//*/
    int a=inf,b=1;
    for(int i=2;i<maxn;i++)
    {
        for(int j=1;j<=2;j++)
            for(int k=0;k<10;k++)
                dig[j][k]=0;
        int t=i;
        while(t)
        {
            dig[1][t%10]++;
            t/=10;
        }
        t=phi[i];
        while(t)
        {
            dig[2][t%10]++;
            t/=10;
        }
        bool c=1;
        for(int j=0;j<10;j++)
            if(dig[1][j]!=dig[2][j])
                c=0;
        if(c)
        {
            if(i*b<phi[i]*a)
            {
                b=phi[i];
                a=i;
            }
        }
    }
    cout<<a;
    return 0;
}
