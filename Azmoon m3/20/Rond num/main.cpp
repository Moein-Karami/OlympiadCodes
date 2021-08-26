#include <bits/stdc++.h>

using namespace std;
int a[8];
int ans;
int mod=10303;
int main()
{
    for(int i=1000000;i<=7801389;i++)
    {
        int t=i;
        for(int j=7;j>=1;j--)
        {
            a[j]=t%10;
            t/=10;
        }
        if(a[2]==a[3]&&a[2]==a[4]&&a[5]==a[6]&&a[5]==a[7])
        {
            ans++;
        }
        else if(a[1]==a[2]&&a[1]==a[3]&&a[4]==a[5]&&a[6]==a[7])
        {
            ans++;
        }
        else if(a[1]==a[2]&&a[3]==a[4]&&a[3]==a[5]&&a[6]==a[7])
        {
            ans++;
        }
        else if(a[1]==a[2]&&a[3]==a[4]&&a[5]==a[6]&&a[5]==a[7])
        {
            ans++;
        }
        else if(a[1]==a[2]&&a[1]==a[3]&&a[4]==a[5]&&a[4]==a[6])
        {
            ans++;
        }
        else if(a[1]==a[2]&&a[1]==a[3]&&a[5]==a[6]&&a[5]==a[7])
        {
            ans++;
        }
        else if(a[1]==a[3]&&a[1]==a[5]&&a[1]==a[7]&&a[2]==a[6]&&a[2]==a[4])
        {
            ans++;
        }
    }
    cout<<(ans*ans)%mod;
    return 0;
}
