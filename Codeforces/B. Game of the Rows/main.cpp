///Chefer


#include <bits/stdc++.h>
#define int long long int
using namespace std;
int a[1000];
main()
{
    int n,k;
    cin>>n>>k;
    int r2,r4;
    r2=2*n;
    r4=n;
    for(int i=1;i<=k;i++)
    {
        cin>>a[i];
        while(a[i]>=4&&r4)
        {
            r4--;
            a[i]-=4;
        }
        while(a[i]>=2&&r2)
        {
            r2--;
            a[i]-=2;
        }
    }
    r2+=2*r4;
    //cerr<<r2<<endl;
    for(int i=1;i<=k;i++)
    {
        if(a[i]==4||a[i]==3)
            r2-=2;
        else if(a[i]!=0)
            r2--;

    }
    if(r2<0)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}
