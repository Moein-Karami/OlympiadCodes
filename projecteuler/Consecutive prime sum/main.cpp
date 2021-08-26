#include <bits/stdc++.h>

using namespace std;
vector <int> ans;
int sum[100000];
bool check(int x)
{
    bool b=1;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)
            b=0;
        if(!b)
            i=x;
    }
    return b;
}
bool check1(int x)
{
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(sum[i]-sum[j-1]==x)
                return 1;
        }
    }
    return 0;
}
int main()
{
    for(int i=2;i<=1000000;i++)
        if(check(i))
            ans.push_back(i);
    for(int i=0;i<ans.size();i++)
        sum[i]=sum[i-1]+ans[i];
    cout<<"W";
    for(int i=ans.size()-1;i>=0;i--)
    {
        if(check1(ans[i]))
        {
            cout<<ans[i];
            return 0;
        }
    }
    return 0;
}
