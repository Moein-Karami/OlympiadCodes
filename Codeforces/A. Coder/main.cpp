#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if((i+j)%2==0)
                ans++;
        }

    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if((i+j)%2==0)
                cout<<"C";
            else
                cout<<".";
        }

        cout<<endl;
    }
    return 0;
}
