#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int l=-1,r=(1e8)*5+5;
    while(l+1!=r)
    {
        int cnt=0;
        int mid=(l+r)/2;
        for(int i=5;i<=mid;i*=5)
        {
            cnt+=mid/i;
        }
        if(cnt>=n)
            r=mid;
        else
            l=mid;
    }
    cout<<r;
    return 0;
}
