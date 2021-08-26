///C


#include <bits/stdc++.h>

using namespace std;
const int maxn=1e5+10;
vector<char> v[maxn];
int r[maxn],c[maxn];
main()
{
        ios_base::sync_with_stdio(false);
        int Q;
        cin>>Q;
        for(int T=1;T<=Q;T++)
        {
            int n,m;
            cin>>n>>m;
            int ans=maxn;
            for(int i=0;i<=max(n,m);i++)
            {
                v[i].clear();
                r[i]=0;
                c[i]=0;
            }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    char tmp;
                    cin>>tmp;
                    v[i].push_back(tmp);
                    if(tmp=='.')
                        r[i]++,c[j]++;
                }
            }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    int tmp=r[i]+c[j];
                    if(v[i][j]=='.')
                        tmp--;
                    ans=min(ans,tmp);
                }
            }
            cout<<ans<<"\n";
        }
}
