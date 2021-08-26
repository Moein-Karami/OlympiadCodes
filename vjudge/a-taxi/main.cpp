#include <iostream>

using namespace std;
int m[100000+10],vb[100000+10],b[100000+10],s[100000+10],vs[100000+10];
int main()
{
    int n,cntvb=0,cntb=0,cnts=0,cntvs=0,x=0;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>m[i];
        if(m[i]==4)
        {
            vb[cntvb]=m[i];
            cntvb++;
        }
        if(m[i]==3)
        {
            b[cntb]=m[i];
            cntb++;
        }
        if(m[i]==2)
        {
            s[cnts]=m[i];
            cnts++;
        }
        if(m[i]==1)
        {
            vs[cntvs]=m[i];
            cntvs++;
        }
    }
    x+=cntvb;
    if(cnts%2==0)
        x+=cnts/2;
    else
    {
        x+=cnts/2+1;
        cntvs-=2;
    }
    if(cntb>=cntvs)
        x+=cntb;
    else
    {
        x+=cntb;
        cntvs-=cntb;
        if(cntvs%4==0)
            x+=cntvs/4;
        else
            x+=cntvs/4+1;
    }
    cout<<x;
    return 0;
}
