#include <bits/stdc++.h>
#define int long long int
using namespace std;
vector <int> v;
int a[10];
bool check()
{
    bool ret=1;
    for(int i=1;i<10;i++)
        if(a[i])
            ret=0;
    return ret;
}
void solve(int x)
{
    if(check())
    {
        bool b=1;
        for(int i=2;i*i<=x;i++)
            if(x%i==0)
                b=0;
        if(b)
            v.push_back(x);
    }
    else
    {
        for(int i=1;i<10;i++)
        {
            if(a[i])
            {
                a[i]--;
                solve(10*x+i);
                a[i]++;
            }
        }
    }
}
main()
{
    for(int i=1;i<10;i++)
        a[i]++;
    ///for(int q=0;q<(1<<10);q++)
    ///{
       /// for(int w=0;w<10;w++)
        ///{
        for(int i=1;i<10;i++)
        {
            if(a[i])
            {
                a[i]--;
                solve(a[i]);
                a[i]++;
            }
        }
       /// }

    ///}

    int ans=0;
    for(int i=1;i<v.size();i++)
        if(v[i]>ans)
            ans=v[i];
    cout<<ans;
    return 0;
}
