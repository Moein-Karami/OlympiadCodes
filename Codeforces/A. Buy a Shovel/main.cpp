///DARK PROGRAMMER


#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int ans=1;
    bool b=1;
    while(b)
    {
        if((n*ans)%10==0||(n*ans)%10==m)
        {
            cout<<ans;
            b=0;
        }
        ans++;
    }
    return 0;
}
