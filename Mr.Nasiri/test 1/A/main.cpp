///DARK PROGRAMMER



#include <iostream>

#define int long long int

using namespace std;

main()
{
    int a,b;
    cin>>a>>b;
    int q=1;
    int cnt=0;
    while(q<=b)
    {
        q*=10;
        cnt++;
    }
    if(q>b)
    {
        cnt--;
        q/=10;
    }
    cout<<cnt<<endl;
    int ans=0;
    int t=1,t1=0;
    for(int i=1;i<=9;i++)
    {
        ans+=max(t1,q-t);
        t*=10;
    }
    cout<<ans;

    return 0;
}
