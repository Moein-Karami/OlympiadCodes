#include <bits/stdc++.h>
#define int long long int
using namespace std;
vector <int> v;
int a[100000000][2];
int check(int x)
{
    for(int i=30;i>=0;i--)
        if(1<<(i)<=x)
            return i;
}
main()
{
    for(int i=1;i<=1e5;i++)
    {
        for(int j=check(i);j>=0;j--)
        {
            if(i&(1<<j))
                v.push_back(1);
            else
                v.push_back(0);
        }

    }
    int ans=0;
    for(int i=1;i<v.size();i++)
    {
        if(v[i-1]==0)
        {
            a[i][0]=a[i-1][0]+1;
            a[i][1]=a[i-1][1];
        }
        if(v[i-1]==1)
        {
            a[i][1]=a[i-1][1]+1;
            a[i][0]=a[i-1][0];
        }
    }
    for(int i=1;i<v.size();i++)
    {
        if(v[i]==0)
            ans+=a[i][0];
        else
            ans+=a[i][1];
    }
    cout<<ans;
    return 0;
}
