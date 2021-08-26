#include <bits/stdc++.h>
#define int long long int
using namespace std;
int a[150][150];
main()
{
    int n,m;
    cin>>n>>m;
    char c;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
           cin>>c;
           a[i][j]=c-'0';
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j])
            {
                ans+=2;
                for(int k=-1;k<=1;k++)
                {
                    for(int l=-1;l<=1;l++)
                    {
                        if(l!=k&&l!=-k)
                        {
                            for(int t=1;t<=a[i][j];t++)
                            {
                                if(a[i+l][j+k]<t)
                                    ans++;
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
