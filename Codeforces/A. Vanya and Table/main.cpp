#include <iostream>
#include <cmath>
using namespace std;
int a[51][51];
int ans;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        ans=ans+((fabs(x1-x2)+1)*(fabs(y1-y2)+1));
    }
    cout<<ans;
    return 0;
}
