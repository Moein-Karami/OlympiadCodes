#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=11969;
int a[70][70][70][70];
int fact[110];
main()
{
    int ans=0;
    fact[0]=1;
    for(int i=1;i<=100;i++)
        fact[i]=(i*fact[i-1])%mod;
    for(int i=0;i<=1;i++)
        for(int j=0;j<=1;j++)
            for(int q=0;q<=1;q++)
                for(int w=0;w<=1;w++)
                    a[i][j][q][w]=fact[i+j+q+w];
                    int tmp=0;
    for(int i=1;i<=1;i++)
    {
        for(int j=1;j<=2;j++)
        {
            for(int q=1;q<=3;q++)
            {
                for(int w=1;w<=4;w++)
                {
                   if(w>1)
                   {
                       a[i][j][q][w]=(a[i][j][q][w-1]*(i+j+q+w-2*(w-1) )/w);
                   }
                   else if(q>1)
                   {
                       a[i][j][q][w]=(a[i][j][q-1][w]*(i+j+q+w-2*(q-1))/q);
                   }
                   else if(j>1)
                   {
                       a[i][j][q][w]=(a[i][j-1][q][w]*(i+j+q+w-2*(j-1))/j);
                   }
                   ans=(ans+a[i][j][q][w]);
                   cout<<i<<" "<<j<<" "<<q<<" "<<w<<" : "<<a[i][j][q][w]<<endl;
                   tmp+=a[i][j][q][w];
                }
            }
        }
    }
    cout<<ans<<" "<<tmp;
    return 0;
}
