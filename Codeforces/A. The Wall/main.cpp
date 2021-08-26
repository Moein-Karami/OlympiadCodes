#include <iostream>

using namespace std;

int main()
{
    int x,y,a,b,m;
    cin>>x>>y>>a>>b;
    if(y>x)
    {
        int tmp=x;
        x=y;
        y=tmp;
    }
    for(int i=1;i<=y;i++)
    {
        if((x*i)%y==0)
        {
            m=x*i;
            i=1e6;
        }
    }

    int ans=(b/m)-((a-1)/m);
    cout<<ans;
    return 0;
}
