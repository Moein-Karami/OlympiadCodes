#include <bits/stdc++.h>

using namespace std;
int a[100000000];
int cnt;
int main()
{
    a[1]=1;
    cnt++;
    for(int i=1;i<=1431;i++)
    {
        for(int j=1;j<=cnt;j++)
            a[j]*=1389;
        for(int j=1;j<=cnt;j++)
        {
            if(j==cnt&&a[cnt]>=10)
                cnt++;
            a[j+1]+=a[j]/10;
            a[j]%=10;
        }
    }
    int b=1;
    for(int i=1;i<=6;i++)
        b*=a[i];
    cout<<b;
    return 0;
}
