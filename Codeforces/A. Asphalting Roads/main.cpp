// DARK PROGRAMMER
#include <iostream>

using namespace std;
int kh[100][100];
int a[100],o[100];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n*n;i++)
    {
        int x,y;
        cin>>x>>y;
        if(!o[x]&&!a[y])
        {
            cout<<i<<" ";
            o[x]=1;
            a[y]=1;
        }
    }
    return 0;
}
