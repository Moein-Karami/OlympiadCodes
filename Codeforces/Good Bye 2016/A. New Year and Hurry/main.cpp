#include <iostream>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int t=4*60;
    t-=k;
    int cnt=1;
    while(t>=5*cnt)
    {
        t-=(cnt*5);
        cnt++;
        n--;
        if(n==0)
            break;
    }

    cout<<cnt-1;
    return 0;
}
