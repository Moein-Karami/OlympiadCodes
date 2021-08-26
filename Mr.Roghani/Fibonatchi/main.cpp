#include <bits/stdc++.h>
#define int long long int
using namespace std;
int a[2][2];
int t[2][2];
void power(int n)
{
    for(int i=0;i<64;i++)
    {
        if((1LL<<i)&n)
        {
            int tmp[2][2]={0};
            for(int j=0;j<2;j++)
            {
                for(int k=0;k<2;k++)
                {
                    for(int l=0;l<2;l++)
                    {
                        tmp[j][k]+=a[j][l]*t[k][l];
                    }
                }
            }
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                    a[j][k]=tmp[j][k];
        }
        int tmp[2][2]={0};
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                for(int l=0;l<2;l++)
                {
                    tmp[j][k]+=t[j][l]*t[k][l];
                }
            }
        }
        for(int j=0;j<2;j++)
            for(int k=0;k<2;k++)
                t[j][k]=tmp[j][k];
    }

}
main()
{
    int n;
    cin>>n;
    n--;
    a[0][0]=1;
    a[1][1]=1;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            if(j!=1||i!=1)
                t[i][j]=1;
    power(n);
    int ans[2];
    ans[0]=a[0][0]+a[0][1];
    ans[1]=a[1][0]+a[1][1];
    cout<<ans[1]<<endl;
    return 0;
}
