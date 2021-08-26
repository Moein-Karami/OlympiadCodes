#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m ;
    if(n==0&&m!=0)
        cout<<"Impossible";
    else
    {
        if(m>=n)
            cout<<n+m-n<<" ";
        else if(m<n)
            cout<<n<<" ";

        if(m>0)
        cout <<m+n-1;
        else cout <<n;
    }
    return 0;
}
