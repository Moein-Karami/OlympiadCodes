#include <bits/stdc++.h>

using namespace std;
const int maxn=1e8+8;
int p[maxn];
int main()
{
    for(int i=2;i<maxn;i++)
        if(!p[i])
            for(int j=i;j<maxn;j+=i)
                p[j]=i;
    long long int ans=0;
    int t,cnt;
    bool b;
    for(int i=2;i<=maxn-8;i++)
    {
        b=0;
        t=i;
        cnt=1;
        while(t>1)
        {
            if(p[t]==p[t/p[t]])
            {
                b=1;
                break;
            }
            t/=p[t];
        }
        if(b)
            continue;
        for(int j=1;j*j<=i;j++)
        {
            if(i%j==0)
            {
                if(p[j+i/j]!=j+i/j)
                {
                    b=1;
                    break;
                }
            }
        }
        if(b)
            continue;
        //cerr<<i<<endl;
        ans+=i;
    }
    cout<<ans;
    return 0;
}
