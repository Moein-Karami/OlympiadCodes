#include <iostream>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x<=k)
            cnt++;
        else
            cnt+=2;
    }
    cout<<cnt;
    return 0;
}
