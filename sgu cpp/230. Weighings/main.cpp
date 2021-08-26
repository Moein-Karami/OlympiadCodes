///Chefer


#include <bits/stdc++.h>

using namespace std;
const int maxn=200;
int cnt[maxn];
vector <int> v[maxn];
queue <int> q;
vector <int> ans;
int answer[maxn];
main()
{
    ios_base::sync_with_stdio(false);
    int n,R;
    cin>>n>>R;
    for(int i=1;i<=R;i++)
    {
        int t1,t2;
        cin>>t1>>t2;
        if(t1==t2)
        {
            cout<<"No solution";
            return 0;
        }
        v[t1].push_back(t2);
        cnt[t2]++;
    }
    for(int i=1;i<=n;i++)
        if(cnt[i]==0)
            q.push(i);
    while(q.size())
    {
        int x=q.front();
        q.pop();
        for(int i=0;i<v[x].size();i++)
        {
            cnt[v[x][i]]--;
            if(cnt[v[x][i]]==0)
                q.push(v[x][i]);
        }
        ans.push_back(x);
    }
    if(ans.size()!=n)
    {
        cout<<"No solution";
        return 0;
    }
    int c=1;
    for(int i=0;i<ans.size();i++)
        answer[ans[i]]=c,c++;
    for(int i=1;i<=n;i++)
            cout<<answer[i]<<" ";
    return 0;
}
