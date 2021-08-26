#include <bits/stdc++.h>

using namespace std;
vector <int> v,tv;
long long int ans;
int aval[2000000];
int mod=10009;
bool check(int x)
{
    bool b=1;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            b=0;
            break;
        }
    }
    if(x==1)
        b=0;
    return b;
}
int solve(int x)
{
    int s=v.size();
    int t=0;
    for(int i=0;i<s;i++)
    {
        for(int j=i;j<s;j++)
        {
            t=0;
            if(v[i]!=0)
            {
                for(int q=i;q<=j;q++)
                    t=(t*10)+v[q];
                if(check(t))
                {
                    ans++;
                    ///cout<<t<<" ";
                    aval[x]++;
                }

            }

        }
    }
    ///cout<<endl;
}
int main()
{
    for(int i=2;i<=1389000;i++)
    {
        v.clear();
        tv.clear();
        int t=i;
        while(t)
        {
            tv.push_back(t%10);
            t/=10;
        }
        for(int j=tv.size()-1;j>=0;j--)
            v.push_back(tv[j]);
        solve(i);
        ///cout<<i<<" "<<aval[i]<<endl<<endl;
    }
    cout<<ans%10009;
    return 0;
}
