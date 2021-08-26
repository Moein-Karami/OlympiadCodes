///Chefer


#include <bits/stdc++.h>

using namespace std;
int a[1000];
main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(a[1]%2==0||a[n]%2==0||n%2==0)
        cout<<"NO";
    else
        cout<<"YES"<<endl;
    return 0;
}
