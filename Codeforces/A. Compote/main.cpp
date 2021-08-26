///DARK PROGRAMMER


#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int ans=0;
    while(a&&b>=2&&c>=4)
    {
        a--;
        b-=2;
        c-=4;
        ans+=7;
    }
    cout<<ans;
    return 0;
}
