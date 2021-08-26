///Chefer


#include <bits/stdc++.h>
#define int long long int
using namespace std;
int dp[15][105][105];
int a[105][105];
bool b[105][105];
main()
{
    int n,q,c;
    cin>>n>>q>>c;
    int t1,t2,t3;
    for(int i=1;i<=n;i++)
    {
        cin>>t1>>t2>>t3;
        a[t1][t2]=t3;
        b[t1][t2]=1;
    }
    for(int k=0;k<=c;k++)
    {
        if(k!=0)
        {
            for(int i=0;i<=100;i++)
                for(int j=0;j<=100;j++)
                    if(b[i][j])
                        a[i][j]++;
        }
        for(int i=0;i<=100;i++)
            for(int j=0;j<=100;j++)
                if(b[i][j])
                    a[i][j]%=(c+1);
        if(b[0][0])
        {
            dp[k][0][0]=a[0][0];

        }
        for(int i=1;i<=100;i++)
        {
            dp[k][i][0]=dp[k][i-1][0];
            if(b[i][0])
                dp[k][i][0]+=a[i][0];
            dp[k][0][i]=dp[k][0][i-1];
            if(b[0][i])
                dp[k][0][i]+=a[0][i];
        }
        for(int i=1;i<=100;i++)
        {
            for(int j=1;j<=100;j++)
            {
                dp[k][i][j]=dp[k][i-1][j]+dp[k][i][j-1]-dp[k][i-1][j-1];
                if(b[i][j])
                    dp[k][i][j]+=a[i][j];
            }
        }
    }
    int t,x1,x2,y1,y2;
    int ans;
    for(int i=1;i<=q;i++)
    {
        cin>>t>>x1>>y1>>x2>>y2;
        if(t>c)
            t=(t%(c+1));
        ans=dp[t][x2][y2]-dp[t][x2][y1-1]-dp[t][x1-1][y2]+dp[t][x1-1][y1-1];

        cout<<ans<<endl;
    }
    return 0;
}
