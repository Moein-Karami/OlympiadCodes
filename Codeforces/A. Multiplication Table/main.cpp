#include <iostream>

using namespace std;

int main()
{
    int n,x,ans=0;
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        if(x/i<=n&&x%i==0&&i*i!=x)
            ans+=1;
        else if(i*i==x)
            ans+=1;
    }
    cout<<ans;
    return 0;
}
