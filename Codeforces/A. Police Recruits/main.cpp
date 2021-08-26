#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    int cnt1=0,cnt2=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>0)
            cnt1+=a[i];
        if(a[i]==-1)
        {
            if(cnt1==0)
                cnt2++;
            else
                cnt1--;
        }
    }
    cout<<cnt2;
    return 0;
}
