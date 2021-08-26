#include <bits/stdc++.h>
#define int long long int
#define f first
#define s seond
using namespace std;
typedef pair<int,int> pii;
const int mod=10357;
int dp[(1<<14)][8];
int po[10];
/*int solve(int mask,int x)
{
    if(x==7)
        return (mask==0);
    int &ret=dp[mask][x];
    if(ret!=-1)
        return ret;
    ret=0;
    vector<int> v;
    int t=mask;
    while(t)
    {
        v.push_back(t%4);
        t/=4;
    }
    for(int i=0;i<7;i++)
        for(int j=i+1;j<7;j++)
            for(int k=j+1;k<7;k++)
                if(v[i]&&v[j]&&v[k])
                    ret=(ret+solve(mask-po[i]-po[j]-po[k],x+1))%mod;
    return ret;
}*/
main()
{
    po[0]=1;
    for(int i=1;i<10;i++)
        po[i]=po[i-1]*4;
    dp[0][7]=1;
    for(int mask=1;mask<(1<<14);mask++)
    {
        for(int x=6;x>=0;x--)
        {
            int &ret=dp[mask][x];
            vector<int> v;
            //v.clear();
            //int ttjog;
            //cerr<<v.size()<<endl;
            /*if(v.size())
            {
                cerr<<"FUCK";
                getchar();
            }*/
            int t=mask;
            for(int i=0;i<7;i++)
            {
                v.push_back(t%4);
                t/=4;
            }
            for(int i=0;i<7;i++)
                for(int j=i+1;j<7;j++)
                    for(int k=j+1;k<7;k++)
                        if(v[i]&&v[j]&&v[k])
                            ret=(ret+dp[mask-po[i]-po[j]-po[k]][x+1])%mod;
        }
    }
    cout<<dp[(1<<14)-1][0];
    return 0;
}
