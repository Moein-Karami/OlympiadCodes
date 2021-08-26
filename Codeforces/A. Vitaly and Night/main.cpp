#include <iostream>

using namespace std;
int a[1000][1000];
int main()
{
    int n,m,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=2*m;j++)
            cin>>a[i][j];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=2*m;j+=2)
            if(a[i][j]||a[i][j+1])
                ans++;
    }
    cout<<ans;
    return 0;
}
