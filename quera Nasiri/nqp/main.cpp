///DARK PROGRAMMER


#include <bits/stdc++.h>

using namespace std;
int a[1010][1010];
int ans[1000010];
int main()
{
    int n,q,p;
    cin>>n>>q>>p;
    int x1,x2,y1,y2;
    for(int i=1;i<=q;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        if(y2<y1)
        {
           swap(x1,x2);
           swap(y1,y2);
        }
        a[x1][y1]++;
        a[x2+1][y1]--;
        a[x1][y2+1]--;
        a[x2+1][y2+1]++;

    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
        }
    }
    for(int i=1;i<=p;i++)
    {
        cin>>x1>>y1;
        ans[i]=a[x1][y1];
    }
    for(int i=1;i<=p;i++)
        cout<<ans[i]<<endl;
    return 0;
}
