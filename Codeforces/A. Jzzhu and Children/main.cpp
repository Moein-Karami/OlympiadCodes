#include <iostream>

using namespace std;
int a[1000];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    bool b=1;
    int ans=0,cnt=0;
    while(b)
    {
        cnt++;
        if(cnt>n)
        cnt=1;
        if(a[cnt]>0)
        {
            a[cnt]-=m;
            ans=cnt;
        }
        b=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]>0)
            {
                b=1;
                i=n+1;
            }
        }
    }
    cout<<ans;
    return 0;
}
