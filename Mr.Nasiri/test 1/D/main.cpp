#include <iostream>

using namespace std;
int m;
int a[100000];
void bet()
{
    for(int i=1;i<=m;i++)
    {

        a[i+1]+=(a[i]/10);
        a[i]=a[i]%10;
        if(a[m+1]>0)
        {
            m++;
        }
    }
}
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        m=1;
        a[1]=1;
        int n;
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            for(int q=1;q<=m;q++)
            {
                a[q]*=j;
            }
            bet();
        }
        for(int j=m;j>=1;j--)
            cout<<a[j];
        cout<<endl;
        for(int j=1;j<=m;j++)
            a[j]=0;
    }
    return 0;
}
