#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int mod=10357;
map<vector<int>,int> mp;
int a[10],b[10];
bool ex[10][10];
main()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=0;i<(1<<(n*n));i++)
    {
        for(int j=0;j<n*n;j++)
        {
            ex[j/n][j%n]=(i&(1<<j));
            a[j/n]+=ex[j/n][j%n];
            b[j%n]+=ex[j/n][j%n];
        }
        vector<int> v;
        for(int j=0;j<n;j++)
        {
            v.push_back(a[j]);
            a[j]=0;
        }
        for(int j=0;j<n;j++)
        {
            v.push_back(b[j]);
            b[j]=0;
        }
        if(!mp[v])
        {
            ans++;
            mp[v]=1;
        }
    }
    cout<<ans;
    return 0;
}
