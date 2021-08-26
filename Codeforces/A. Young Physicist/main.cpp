#include <iostream>

using namespace std;

int main()
{
    int n,ans=0,ans2=0,ans3=0;
    cin>>n;
    int a[n][3];
    for(int i=0;i<n;i++)
    {
        for(int j=0; j<3;j++)
            cin>>a[i][j];
    }
    for(int i=0;i<n;i++)
    {
        ans+=a[i][0];
        ans2+=a[i][1];
        ans3+=a[i][2];
    }


    if(!ans&&!ans2&&!ans3)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
