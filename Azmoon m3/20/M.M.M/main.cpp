#include <bits/stdc++.h>

using namespace std;
int win[61];
bool b[61];
int mod=10303;
void clean()
{
    for(int i=1;i<=60;i++)
        b[i]=0;
}
int main()
{
    for(int i=1;i<=60;i++)
    {
        int s=60;
        clean();
        b[i]=1;
        s--;
        int t=i;
        int tmp1=t;
        int tmp2=0;
        while(s)
        {
            while(tmp2<t)
            {
                tmp1++;
                tmp1%=60;
                if(tmp1==0)
                    tmp1=60;
                if(!b[tmp1])
                    tmp2++;
            }
            b[tmp1]=1;
            s--;
            t=tmp1;
            tmp2=0;
        }
        win[i]=t;
    }
    long long int ans=1;
    for(int i=1;i<=60;i++)
    {
        ans=(ans*win[i])%mod;;
    }

    ans%=mod;
    cout<<ans;
    return 0;
}
