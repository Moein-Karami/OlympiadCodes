///Chefer


#include <bits/stdc++.h>

using namespace std;
int a[100010];
main()
{
    ios_base::sync_with_stdio(false);
    int n,x;
    cin>>n>>x;
    if(n==2&&x==0)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
    if(n==1)
    {
        cout<<x;
        return 0;
    }
    if(n==2)
    {
        cout<<x<<" "<<0;
        return 0;
    }
    int y=0;
    for(int i=1;i<=n-1;i++)
    {
        y^=i;
        a[i]=i;
    }
    if(y==x)
    {
        cout<<0<<" ";
        for(int i=1;i<n;i++)
            cout<<i<<" ";
        return 0;
    }
    int z=y^x;
    a[n]=(1<<18);
    if(z==1)
    {
        a[2]=2^(1<<18)^z;
    }
    else
    {
        a[1]=1^(1<<18)^z;
    }
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
}
