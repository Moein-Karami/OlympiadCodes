#include <bits/stdc++.h>

using namespace std;
vector <int> ans;
int q=3;
int p=1;
void solve(vector <int> t,int a)
{
    if(a<1)
        return;
    int s=t.size();
    if(a==1)
    {
        s--;
        if(t[0]==1)
        {
            if(s%2==0)
                t.push_back(2);
            else
                t.push_back(1);
        }
        else
        {
            if(s%2==1)
                t.push_back(2);
            else
                t.push_back(1);
        }
        s++;
        if(s>ans.size())
            return ;
        else if(s<ans.size())
        {
            ans.clear();
            for(int i=1;i<=s;i++)
                ans.push_back(t[i]);

        }
        else
        {
            for(int i=1;i<=s;i++)
            {
                if(t[i]<ans[i])
                {
                    ans.clear();
                    for(int j=1;j<=s;j++)
                        ans.push_back(t[j]);
                    break;
                }
            }

        }
    }
    if(t[0]%2==0)
    {
        if(s%2==0)
        {
            t.push_back(1);
            solve(t,a-1);
            t[s]=2;
            solve(t,a-3);
        }
        else
        {
            t.push_back(1);
            solve(t,a);
            if(a%3==0)
            {
                t[s]=2;
                solve(t,a/3);
            }
        }
    }
    else
    {
       if(s%2==1)
        {
            t.push_back(1);
            solve(t,a-1);
            t[s]=2;
            solve(t,a-3);
        }
        else
        {
            t.push_back(1);
            solve(t,a);
            if(a%3==0)
            {
                t[s]=2;
                solve(t,a/3);
            }
        }
    }
}
main()
{
    for(int i=0;i<=10000;i++)
        ans.push_back(3);
    vector <int> t;
    t.push_back(1);
    t.push_back(1);

    int a=13781378;
    solve(t,a-1);
    t[1]=2;
    solve(t,a-3);
    t[0]=2;
    t[1]=1;
    solve(t,a);

    for(int i=ans.size()-1;i>=0;i--)
        cout<<ans[i];
    return 0;
}
