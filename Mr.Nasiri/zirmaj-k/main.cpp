#include <iostream>

using namespace std;
const int maxn=10000;
int maj[maxn];
int bit[maxn];
int cnt;
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>maj[i];
    for(int i=1;i<(1<<n);i++)
    {
        for(int j=0;j<n;j++)
        {
            bit[j]=(i&(1<<j));
            cnt+=(i&(1<<j))>0;
        }
        if(cnt==k)
        {
            cout<<"{";
            for(int i=1;i<=n;i++)
            {
                if(bit[i-1])
                    cout<<maj[i]<<" ";
            }
            cout<<"}"<<endl;
        }
        for(int i=0;i<=n;i++)
        {
            bit[i]=0;
        }
        cnt=0;

    }
    return 0;
}
