///Chefer


#include<bits/stdc++.h>
#define int long long int
using namespace std;
const int mod=10487;
bool b[2*mod+20];
vector<int> v;
vector<int> s[mod+20];
main()
{
    b[1]=1;
    for(int i=2;i<2*mod+20;i++)
    {
        if(!b[i])
        {
            if(i<=mod)
                v.push_back(i);
            for(int j=i*i;j<2*mod+20;j+=i)
                b[j]=1;
        }
    }
    for(int i=0;i<v.size();i++)
    {
        int x=v[i];
        while(x)
        {
            s[i].push_back(x%2);
            x/=2;
        }
        reverse(s[i].begin(),s[i].end());
    }
    int ans=1;
    for(int i=0;i<v.size();i++)
    {
        for(int j=i+1;j<v.size();j++)
        {
            //cerr<<v[i]<<" "<<v[j]<<endl;
            if(!b[v[i]+v[j]+1])
            {
                //cerr<<v[i]<<" "<<v[j]<<endl;
                int x=0;
                while(x<s[i].size()&&s[i][x]==s[j][x])
                    x++;
                ans=(ans*(s[i].size()+s[j].size()-2*x))%mod;
            }
        }
    }
    cout<<ans;
    return 0;
}
