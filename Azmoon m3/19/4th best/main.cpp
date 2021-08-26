#include <iostream>

using namespace std;
int a[10000010];
int main()
{
    a[1]=1;
    for(int i=2;i<=10000000;i++)
    {
        int ans=1;
        int t=i;
        for(int j=2;j*j<=t;j++)
        {
            int tmp=1;
            while(t%j==0)
            {
                t/=j;
                tmp++;
            }
            ans*=tmp;
        }
        if(t>1)
            ans*=2;
        a[i]=ans;
    }
    cout<<a[8648640]<<endl;;
    for(int j=1;j<=3;j++)
    {
        int maxi=0;
        for(int i=1;i<=10000000;i++)
            if(a[i]>a[maxi])
                maxi=i;
        cout<<maxi<<" "<<a[maxi]<<endl;
        a[maxi]=0;
    }
    int maxi=0;
    for(int i=1;i<=10000000;i++)
        if(a[i]>a[maxi])
            maxi=i;
    cout<<maxi%10099;
    return 0;
}
