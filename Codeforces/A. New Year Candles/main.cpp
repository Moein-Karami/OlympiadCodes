#include <iostream>

using namespace std;

int main()
{
    int a,b,cnt=0,cnt2=0;
    cin>>a>>b;
    for(int i=a;i>0;i--)
    {
        cnt++;
        cnt2++;
        if(cnt2==b)
        {
            i++;
            cnt2=0;
        }
    }
    cout<<cnt;
    return 0;
}
