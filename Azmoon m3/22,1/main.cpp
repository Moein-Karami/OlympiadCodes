#include <bits/stdc++.h>

using namespace std;
const int mod=12263;
vector <int> t,v;
bool b[mod+10];
main()
{
    for(int i=2;i<=mod;i++)
        if(!b[i])
            for(int j=i*i;j<=mod;j+=i)
                b[j]=1;
    t.push_back(2);
    t.push_back(2);
    for(int i=3;i<=mod;i++)
    {
        if(b[i-1])
            t.push_back(2);
        else
            t.push_back(1);
    }
    for(int i=t.size()-1;i>=0;i--)
        v.push_back(t[i]);

    t.clear();
    for(int j=1;j<=mod;j++)
    {
        if(j%2==1)
        {
            t.clear();
            for(int i=0;i<v.size();i++)
            {
                if((v[i]==1&&v[i+1]==2)||(v[i]==2&&v[i-1]==1))
                    t.push_back(3-v[i]);
                else
                    t.push_back(v[i]);
            }
        }
        else
        {
            v.clear();
            for(int i=0;i<t.size();i++)
            {
                if((t[i]==1&&t[i+1]==2)||(t[i]==2&&t[i-1]==1))
                    v.push_back(3-t[i]);
                else
                    v.push_back(t[i]);
            }
        }
    }
    int ans=0;
    for(int i=0;i<t.size();i++)
    {
            if(v[i]==2bjhiy)
                ans++;
    }
    cout<<ans;
    return 0;
}
