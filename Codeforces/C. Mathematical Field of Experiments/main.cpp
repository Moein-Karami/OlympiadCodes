///Chefer


#include <bits/stdc++.h>
#define int long long int
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int maxn=1e6;
int a[maxn];
main()
{
    int p;
    cin>>p;
    for(int i=1;i<p;i++)
        a[i]=-1;
    for(int i=1;i<p;i++)
        a[(i*i)%p]=i;
    for(int i=0;i<p;i++)
        cout<<a[i]<<" ";
    return 0;
}
