#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a,m;
    cin>>a>>m;
    if(m>0)
    {
        m=m%n;
        int ans=(a+m)%n;
        if(ans==0)
            ans=n;
        cout<<ans;
    }
    else
    {
        m=-m;
        m=m%n;
        for(int i=1;i<=m;i++)
        {
            a--;
            if(a==0)
                a=n;

        }
        cout<<a;
    }
    return 0;
}
