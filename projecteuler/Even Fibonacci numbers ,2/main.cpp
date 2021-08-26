#include <iostream>

using namespace std;
int f[10000];
int main()
{
    int ans=0;
    f[1]=1;
    f[2]=2;
    ans=2;
    for(int i=3;i<10000;i++)
    {
        f[i]=f[i-1]+f[i-2];
        if(f[i]<4000000)
        {
            if(f[i]%2==0)
            ans+=f[i];
        }
        else
            i=10000;
    }
    cout<<ans;
    return 0;
}
