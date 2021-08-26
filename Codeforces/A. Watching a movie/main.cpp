///DARK PROGRAMMER


#include <iostream>

using namespace std;

int main()
{
    int n,x;
    cin>>n>>x;
    int s=0;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int y,d;
        cin>>y>>d;
        while(x<=y-s-1)
            s+=x;
        ans+=(d-s);
        s=d;
    }
    cout<<ans;
    return 0;
}
