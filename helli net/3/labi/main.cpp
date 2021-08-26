///EXPERT




#include <bits/stdc++.h>

using namespace std;
int a[1000000];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int b,c;
    for(int i=1;i<=m;i++)
    {
        cin>>b>>c;
        a[c]+=a[b];
        a[b]=0;
    }
    int maxi=0,j=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>maxi)
        {
            maxi=a[i];
            j=i;
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(a[i]==maxi)
            cnt++;
    if(cnt>1)
        cout<<-1;
    else
        cout<<j;

    return 0;
}
