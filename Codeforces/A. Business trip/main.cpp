#include <iostream>
#include <algorithm>
using namespace std;
int a[13];
int main()
{
    int k,sum=0,cnt=0;
    cin>>k;
    for(int i=1;i<=12;i++)
        cin>>a[i];
    sort(a,a+13);
    for(int i=12;i>=0;i--)
    {
       if(sum>=k)
       {
           cout<<cnt;
           return 0;
       }
       cnt++;
       sum+=a[i];
    }
    cout<<-1;
    return 0;
}
