#include <bits/stdc++.h>
#define int long long int
using namespace std;
int a[8];
int ans;
int mod= 10357;
void solve(int x)
{
    if(x==8)
    {
        ans++;
        return;
    }
    for(int i=1;i<=7;i++)
    {
        if(a[i])
        {
            a[i]--;
            for(int j=i+1;j<=7;j++)
            {
                if(a[j])
                {
                    a[j]--;
                    for(int k=j+1;k<=7;k++)
                    {
                        if(a[k])
                        {
                            a[k]--;
                            solve(x+1);
                            a[k]++;
                        }

                    }
                    a[j]++;
                }
            }
            a[i]++;
        }
    }
}
main()
{
    for(int i=1;i<=7;i++)
        a[i]=3;

    for(int i=1;i<=7;i++)
    {
        a[i]--;
        for(int j=i+1;j<=7;j++)
        {
            a[j]--;
            for(int k=j+1;k<=7;k++)
            {
                a[k]--;
                solve(2);
                a[k]++;
            }
            a[j]++;
        }
        a[i]++;
    }
    cout<<ans%mod;
    return 0;
}
