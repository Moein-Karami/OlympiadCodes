#include <bits/stdc++.h>

using namespace std;
const int maxn=100001*2;
vector <int> v[maxn];
queue <int> q;
int ans[maxn];
bool b[maxn];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=100000;i++)
    {
        v[i].push_back(i*2);
        v[i].push_back(i-1);
    }
    ans[n]=0;
    b[n]=1;
    q.push(n);
    while(q.size())
    {
        int t=q.front();
        for(int i=0;i<v[t].size();i++)
        {
            if(!b[v[t][i]])
            {
                ans[v[t][i]]=ans[t]+1;
                b[v[t][i]]=1;
                q.push(v[t][i]);
                if(v[t][i]==m)
                {
                    cout<<ans[t]+1;
                    return 0;
                }
            }
        }
        q.pop();
    }
    return 0;
}
