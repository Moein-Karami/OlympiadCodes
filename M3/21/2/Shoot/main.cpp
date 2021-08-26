#include <bits/stdc++.h>
#define f first
#define s second
#define int long long int
using namespace std;
typedef pair<int,int> pii;
int ans[20][20];
int mod=10687;
pii tmp[4]={pii(-1,0),pii(0,1),pii(1,0),pii(0,-1)};
main()
{
    int x=0,y=0;
    for(int i=1;i<mod;i++)
    {
        x=(x+9)%9;
        y=(y+9)%9;
        int r=ans[x][y]%4;
        ans[x][y]++;
        x+=tmp[r].f;
        y+=tmp[r].s;
    }
    int ret=1;
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        ret=(ret*ans[i][j])%mod;
    cout<<ret;
    return 0;
}
