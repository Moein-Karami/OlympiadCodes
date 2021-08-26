///DAEK PROGRAMMRE


#include <iostream>
#define int long long int
using namespace std;

main()
{
    int n,m;
    cin>>n>>m;
    int a[m];
    for(int i=0;i<m;i++)
        cin>>a[i];
    int j=1,ans=0;;
    for(int i=0;i<m;i++)
    {
        if(a[i]>=j)
            ans+=a[i]-j;
        else
        {
            ans+=a[i]+n-j;
        }
        j=a[i];
    }
    cout<<ans;
    return 0;
}
