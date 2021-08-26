#include <iostream>

using namespace std;
int a[1000000],b[1000000];
int main()
{
    int n,m;
    cin>>n>>m;
    int k1,k2;
    cin>>k1>>k2;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    if(b[m-k2+1]>a[k1])
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
