#include <iostream>

using namespace std;
int a[2000],b[2000];
int main()
{
    a[1]=1;
    b[1]=1;
    int cnta=1,cntb=1;
    for(int i=3;i<=1000000000;i++)
    {
        if(i%2==1)
            for(int j=1;j<=max(cnta,cntb);j++)
                a[j]=a[j]+b[j];
        else
            for(int j=1;j<=max(cnta,cntb);j++)
                b[j]=a[j]+b[j];
        for(int j=1;j<=max(cnta,cntb);j++)
        {
            a[j+1]+=a[j]/10;
            b[j+1]+=b[j]/10;
            if(a[cnta+1])
                cnta++;
            if(b[cntb+1])
                cntb++;
            a[j]%=10;
            b[j]%=10;
        }
        if(cnta>=1000||cntb>=1000)
        {
            cout<<i<<endl;
            return 0;
        }

    }
    return 0;
}
