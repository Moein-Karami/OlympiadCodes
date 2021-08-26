#include <iostream>

using namespace std;
int a[100000000];
long long int maxn=100000000;
int main()
{
    for(int i=2;i<maxn;i++)
        if(!a[i])
            for(int j=i;j<maxn;j+=i)
                a[j]+=i;
    int ans=0;
    for(int i=2;i<maxn;i++)
        if(a[i]>a[ans])
            ans=i;
    cout<<ans;
    return 0;
}
