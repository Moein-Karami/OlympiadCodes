#include <bits/stdc++.h>
#define int long long int
using namespace std;
int a[30][30];
int ans;
main()
{

    for(int i=1;i<=20;i++)
        for(int j=1;j<=20;j++)
            cin>>a[i][j];
    int t=1;
    for(int i=1;i<=20;i++)
    {
        for(int j=1;j<=20;j++)
        {
            t=1;
            int s=ans;
            for(int k=0;k<4;k++)
                t*=a[i][j+k];
            ans=max(t,ans);
            t=1;
            for(int k=0;k<4;k++)
                t*=a[i+k][j+k];
            ans=max(t,ans);
            t=1;
            for(int k=0;k<4;k++)
                t*=a[i+k][j];
            ans=max(t,ans);
            t=1;
            for(int k=0;k<4;k++)
                t*=a[i+k][j-k];
            ans=max(t,ans);
            if(s!=ans)
                cout<<i<<" "<<j<<endl;
        }
    }
    cout<<ans;
    return 0;
}
