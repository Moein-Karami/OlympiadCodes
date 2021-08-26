#include <bits/stdc++.h>

using namespace std;
int cnt,t,ans,a[1001][1001],b[1001][1001],x;
bool check()
{
    for(int i=1;i<=x;i++)
        for(int j=1;j<=x;j++)
            if(a[i][j]!=b[i][j])
                return 1;
    return 0;
}
int main()
{
    cin>>x;
    for(int i=1;i<=x;i++)
        for(int j=1;j<=x;j++)
            a[i][j]=i*j;

    while(check())
    {
        ans++;
        if(ans%2==1)
        {
            for(int i=1;i<=x;i++)
            {
                for(int j=1;j<=x;j++)
                {
                    cnt=0,t=0;
                    for(int q=-1;q<=1;q++)
                    {
                        for(int w=-1;w<=1;w++)
                        {
                            if(i+q>=1&&i+q<=x&&j+w>=1&&j+w<=x)
                            {
                                cnt++;
                                t+=a[i+q][j+w];
                            }
                        }
                    }
                    b[i][j]=t/cnt;
                }
            }
        }
        else
        {
            for(int i=1;i<=x;i++)
            {
                for(int j=1;j<=x;j++)
                {
                    cnt=0,t=0;
                    for(int q=-1;q<=1;q++)
                    {
                        for(int w=-1;w<=1;w++)
                        {
                            if(i+q>=1&&i+q<=x&&j+w>=1&&j+w<=x)
                            {
                                cnt++;
                                t+=b[i+q][j+w];
                            }
                        }
                    }
                    a[i][j]=t/cnt;
                }
            }
        }

    }
    cout<<ans<<" "<<a[1][1];
    return 0;
}
