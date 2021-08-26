///I'm Chefer now ;)



#include <bits/stdc++.h>
#define int long long int

using namespace std;
int a[100000];
main()
{
    cout<<std::fixed;
    cout.precision(8);
    int n;
    double n1,n2;
    cin>>n>>n1>>n2;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        a[i]*=-1;
    }
    sort(a,a+n);
    double s=0,s2=0;
    if(n1>n2)
        swap(n1,n2);
    for(int i=0;i<n1;i++)
    {
        s+=(a[i]*-1);
    }
    s/=n1;
    for(int i=n1;i<n2+n1;i++)
    {
        s2+=(a[i]*-1);
    }
    s2/=n2;
    cout<<s+s2;
    return 0;
}
