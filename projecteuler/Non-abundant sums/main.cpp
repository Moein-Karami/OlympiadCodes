#include <bits/stdc++.h>

using namespace std;
bool check(int x)
{
    int ans=0;
    for(int i=1;i<x;i++)
        if(x%i==0)
            ans+=i;

    return (ans>x);
}
bool in[100000];
int main()
{
    int ans=0;
    bool b;
    for(int i=1;i<=28124;i++)
        in[i]=check(i);
    for(int i=1;i<=28124;i++)
    {
        b=0;
        for(int j=1;j<=i;j++)
        {
            if(in[j]&&in[i-j])
                b=1;
            if(b)
                j=i;
        }
        if(!b)
            ans+=i;
    }
    cout<<ans;
    return 0;
}
