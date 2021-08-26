///Chefer


#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second

using namespace std;
typedef pair<int,int> pii ;
const int maxn=3030;
int n,m,k;
vector <pii> v[maxn];
pii  a[maxn][maxn];
main()
{
    cin>>n>>m>>k;
    int t1,t2,t3;
    for(int i=1;i<=m;i++)
    {
        cin>>t1>>t2;
        a[t1][t2].f=1;
        a[t2][t1].f=1;
    }
    for(int i=1;i<=k;i++)
    {
        cin>>t1>>t2>>t3;
        if(a[t1][t3].s==t2)
        {
            a[t1][t3].s=0;
            a[t1][t3].f=0;
        }
    }
    return 0;
}
