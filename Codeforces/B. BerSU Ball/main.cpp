///DARK PROGRAMMER



#include <bits/stdc++.h>

using namespace std;
int b[1000];
int g[1000];
bool g1[1000];
bool b1[1000];
int main()
{
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>b[i];
    cin>>m;
    for(int i=0;i<m;i++)
        cin>>g[i];
    sort(b,b+n);
    sort(g,g+m);
    int p=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!b1[i]&&fabs(b[i]-g[j])<=1&&!g1[j])
            {
                ans++;
                g1[j]=1;
                b1[i]=1;
            }
        }

    }

    cout<<ans;
    return 0;
}
