#include <iostream>

using namespace std;
int a[1000];
int main()
{
    int n;
    cin>>n;
    int sum=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    int p;
    p=n/2;
    int jam;
    jam=sum/p;
    for(int i=1;i<=n;i++)
    {
        for (int j=i+1;j<=n;j++)
        {
            if(a[i]+a[j]==jam)
            {
                cout<<i<<" "<<j<<endl;
                a[i]=0;
                a[j]=0;
            }
        }
    }
    return 0;
}
