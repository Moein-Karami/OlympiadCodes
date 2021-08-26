#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int maxn=5e7+6;
vector<int> v;
bool b[maxn];
bool mark[maxn];
main()
{
    for(int i=2;i<maxn;i++)
    {
        if(!b[i])
        {
            if(i*i<maxn)
                v.push_back(i);
            for(int j=i*i;j<maxn;j+=i)
                b[j]=1;
        }
    }
    int ans=0;
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v.size();j++)
        {
            for(int k=0;k<v.size();k++)
            {
                if(v[i]*v[i]+v[j]*v[j]*v[j]+v[k]*v[k]*v[k]*v[k]<=maxn-6)
                {
                    if(!mark[v[i]*v[i]+v[j]*v[j]*v[j]+v[k]*v[k]*v[k]*v[k]])
                        ans++;
                    mark[v[i]*v[i]+v[j]*v[j]*v[j]+v[k]*v[k]*v[k]*v[k]]=1;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
