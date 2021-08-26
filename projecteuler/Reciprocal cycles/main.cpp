#include <bits/stdc++.h>
#define int long long int
using namespace std;
bool b[10];
int a[10000];
main()
{
    for(int i=2;i<=1000;i++)
    {
        for(int j=0;j<=9;j++)
            b[j]=0;
        int t=1;
        int cnt=0;
        t=(t*10)%i;
        while(t!=0&&!b[t])
        {
            b[t]=1;
            while(t)
            t=(t*10)%i;
            cnt++;
        }
        if(!t)
            a[i]=0;
        else
            a[i]=cnt;
    }
    int ans=0;
    for(int i=2;i<=1000;i++)
        if(a[ans]<a[i])
            ans=i;
        cout<<ans;

    return 0;
}
