///Chefer


#include <bits/stdc++.h>

using namespace std;
const int maxn=110;
int a[maxn][maxn];
int p1[maxn][maxn],p2[maxn][maxn];
int ans[maxn][maxn];
int n,m,h,v;
int s;
bool cut[maxn];
int tmp[maxn];
main()
{
    ios_base::sync_with_stdio(false);
    int T;
    cin>>T;
    for(int Q=1;Q<=T;Q++)
    {
        char c;
        int cnt=0;
        cin>>n>>m>>h>>v;
        for(int i=1;i<maxn;i++)
            cut[i]=0;
        for(int i=1;i<maxn;i++)
            for(int j=1;j<maxn;j++)
                p1[i][j]=0,p2[i][j]=0;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>c;
                p1[i][j]=p1[i][j-1];
                p2[i][j]=p2[i-1][j];
                if(c=='@')
                {
                    a[i][j]=1;
                    p1[i][j]++;
                    p2[i][j]++;
                    cnt++;
                }
                else
                    a[i][j]=0;
            }
        }
        if(cnt==0)
        {
            cout<<"Case #"<<Q<<": POSSIBLE\n";
            continue;
        }
        if(cnt%((h+1)*(v+1))!=0)
        {
            cout<<"Case #"<<Q<<": IMPOSSIBLE\n";
            continue;
        }
        else s=cnt/((h+1)*(v+1));
        cnt=0;
        int t=0;
        bool b=0;
        for(int i=n;i>h;i--)
        {
            vector <int> soot;
            cnt=0;
            t=0;
            for(int j=1;j<=m;j++)
            {
                t+=p2[n][j]-p2[i-1][j];
                if(t>s)
                    break;
                if(t==s)
                {
                    t=0;
                    cut[j]=1;
                    soot.push_back(j);
                    //cerr<<"CUT : "<<j<<endl;
                    if(j!=m)
                        cnt++;
                }
            }
            if(t!=0||cnt!=v)
                continue;
            int mark=1;
            int sum=0;
            int g=0;
            for(int j=i-1;j>=1;j--)
            {
                mark=1;
                for(int k=1;k<=m;k++)
                {
                    tmp[mark]+=a[j][k];
                    mark+=cut[k];
                }
                g=0;
                for(int k=1;k<=cnt+1;k++)
                {
                    if(tmp[k]>s)
                        g=-1;
                    else if(tmp[k]==s)
                        g=1;
                }
                if(g)
                    sum++;
                for(int k=1;k<=cnt+1;k++)
                {
                    if(g&&tmp[k]!=s)
                        g=-1;
                    if(g)
                        tmp[k]=0;
                }
                if(g==-1)
                {
                    for(int k=0;k<soot.size();k++)
                        cut[soot[k]]=0;
                    break;
                }
            }
            for(int k=0;k<soot.size();k++)
                cut[soot[k]]=0;
            for(int k=1;k<=cnt+1;k++)
                    tmp[k]=0;
            if(g!=-1&&sum==h)
                b=1;
            if(b)
            {
                //cerr<<i<<endl;
                break;
            }
        }
        if(b)
            cout<<"Case #"<<Q<<": POSSIBLE\n";
        else
            cout<<"Case #"<<Q<<": IMPOSSIBLE\n";
    }
    return 0;
}
