#include <bits/stdc++.h>
#define int long long int
using namespace std;
int ans;
int a[10];
bool check(int x)
{
    for(int i=0;i<10;i++)
        a[i]=0;
    for(int i=1;i<=8;i++)
    {
        a[x%10]++;
        x/=10;
    }
    int ret=0;
    for(int i=0;i<10;i++)
        if(a[i]>1)
            ret++;
    if(ret>2)
        return 1;
    return 0;
}
main()
{
    for(int i=0;i<=99999999;i++)
    {
        ans+=check(i);
    }
    cout<<ans;
    return 0;
}
