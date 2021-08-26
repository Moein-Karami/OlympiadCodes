#include <iostream>

using namespace std;
const int maxn=1e8;
int a[maxn],prime[maxn];
bool b[maxn];
int main()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=q;i++)
        cin>>a[i];
    b[1]=0;
    prime[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!b[i])
        {
            prime[i]=i;
            for(int j=i*i;j<=n;j+=i)
            {
                b[j]=1;
                prime[j]=i;
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        int j=a[i];
        while(b[j])
        {
            cout<<prime[j]<<" ";
            j=j/prime[j];

        }
        cout<<prime[j]<<endl;
    }
    return 0;
}
