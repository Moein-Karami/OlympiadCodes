///C


#include <bits/stdc++.h>
//#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int maxn=2e5+5;
int a[5][5][maxn],inf=1e9;
main()
{
    ios_base::sync_with_stdio(false);
    int Q;
    cin>>Q;
    for(int T=1;T<=Q;T++)
    {
        int n,k,ans=inf;
        cin>>n>>k;
        string s;
        cin>>s;
        for(int i=0;i<s.size();i++)
        {
            if(i)
                for(int j=0;j<3;j++)
                    for(int q=0;q<3;q++)
                        a[j][q][i]=a[j][q][i-1];
            if(s[i]=='R')
                a[0][i%3][i]++;
            else if(s[i]=='G')
                a[1][i%3][i]++;
            else
                a[2][i%3][i]++;
        }
        for(int i=0;i<=n-k;i++)
        {
            for(int j=0;j<3;j++)
            {
                int p1=a[j][i%3][i+k-1],p2=a[(j+1)%3][(i+1)%3][i+k-1],p3=a[(j+2)%3][(i+2)%3][i+k-1];
                if(i)
                {
                    p1-=a[j][i%3][i-1];
                    p2-=a[(j+1)%3][(i+1)%3][i-1];
                    p3-=a[(j+2)%3][(i+2)%3][i-1];
                }
                ans=min(ans,k-p1-p2-p3);
            }
        }
        cout<<ans<<"\n";
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                for(int q=0;q<=n;q++)
                    a[i][j][q]=0;
    }
}
