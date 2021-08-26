///DARK ROGRAMMER


#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    bool b=1;
    int ans=0;
    while(b)
    {
        ans++;
        for(int i=2;i*i<=n*ans+1;i++)
        {
            if((n*ans+1)%i==0)
            {
                b=0;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
