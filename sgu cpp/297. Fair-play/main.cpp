///Chefer


#include <bits/stdc++.h>

using namespace std;

main()
{
    int n,m;
    cin>>n>>m;
    int t;
    int s=0;
    for(int i=1;i<=m;i++)
        cin>>t,s+=t;
    cout<<s%n;
    return 0;
}
