#include <iostream>

using namespace std;

int main()
{
    int ans=0;
    for(int i=1;i<=10000000;i++)
    {
        int t=i;
        int tmp=0;
        while(t)
        {
            tmp+=(t%10)*(t%10)*(t%10)*(t%10)*(t%10);
            t/=10;
        }
        if(i==tmp)
            ans+=tmp,cout<<i<<endl;
    }
    cout<<ans;
    return 0;
}
