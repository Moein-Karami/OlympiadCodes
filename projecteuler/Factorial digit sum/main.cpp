#include <iostream>

using namespace std;
int f[10000];
void bet()
{
    for(int i=1;i<=9998;i++)
    {
        f[i+1]+=(f[i]/10);
        f[i]%=10;
    }
}
int main()
{
    f[1]=1;
    for(int i=1;i<=100;i++)
    {
        for(int j=1;j<=9999;j++)
        {
            f[j]*=i;
        }
        bet();
    }
    int ans=0;
    for(int i=1;i<=9999;i++)
        ans+=f[i];
    cout<<ans;
    return 0;
}
