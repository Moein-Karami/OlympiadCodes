#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n,x;
    cin>>n>>x;
    int s=0;
    for(int i=1;i<=n;i++)
    {
        int q;
        cin>>q;
        s+=q;
    }
    s=fabs(s);
    if(s%x==0)
        cout<<s/x;
    else
        cout<<s/x+1;
    return 0;
}
