#include <bits/stdc++.h>
#define int long long int
using namespace std;
bool b[1000001];
int a[1000001];
vector <int> v;
int sum[1000001];
main()
{
    for(int i=2;i<=1000000;i++)
    {
        if(!b[i])
        {
            v.push_back(i);
            for(int j=i*i;j<=1000000;j+=i)
                b[j]=1;
        }
    }
    for(int i=0;i<v.size();i++)
        sum[i]=sum[i-1]+v[i];
    for(int i=0;i<v.size();i++)
    {
        for(int j=i;j<v.size();j++)
        {
            if(sum[j]-sum[i-1]>1000000)
                j=v.size();
            else
            {
                if(!b[sum[j]-sum[i-1]])
                {
                    a[sum[j]-sum[i-1]]=max(j-i+1,a[sum[j]-sum[i-1]]);
                }

            }
        }
    }
    int ans=0;
    for(int i=0;i<1000000;i++)
    {
        if(a[i]>a[ans])
            ans=i;
    }
    cout<<ans;
    return 0;
}
