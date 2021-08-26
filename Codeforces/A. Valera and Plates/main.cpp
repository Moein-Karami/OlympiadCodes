///DARK PROGRAMMER


#include <iostream>

using namespace std;

int main()
{
    int ans=0,n,m,k;
    cin>>n>>m>>k;
    int h;
    for(int i=1;i<=n;i++)
    {
        cin>>h;
        if(h==1&&m)
            m--;
        else if(h==2&&k)
            k--;
        else
            ans++;
    }
    cout<<ans;
    return 0;
}
