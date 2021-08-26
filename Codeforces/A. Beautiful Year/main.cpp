#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    bool b=1;
    while(b)
    {
        n++;
        int x,y,z,k;
        int tmp=n;
        x=tmp%10;
        tmp/=10;
        y=tmp%10;
        tmp/=10;
        z=tmp%10;
        tmp/=10;
        k=tmp%10;
        tmp/=10;
        if(x!=y&&x!=z&&x!=k&&y!=z&&y!=k&&z!=k)
            b=0;
    }
    cout<<n;
    return 0;
}
