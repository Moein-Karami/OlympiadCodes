#include <bits/stdc++.h>
#define int long long int
using namespace std;
int ans;
int a[100];
int m[2000000];
int mod=22943;

main()
{
    int cnt=1;
    a[0]=1;
    m[1]=1;
    for(int i=2;i<=1000100;i++)
    {
        int q=0;
        while(a[q]==9)
        {
            a[q]=1;
            q++;
        }
        if(a[q]==0)
            a[q]++;
        else if(a[q]==3)
            a[q]+=4;
        else
            a[q]+=2;
        for(int j=0;j<=15;j++)
            m[i]+=a[j];
    }
    int ans=1;
    for(int i=1000000;i<=1000100;i++)
        ans=(ans*m[i])%mod;
    cout<<ans%mod;
    return 0;
}
