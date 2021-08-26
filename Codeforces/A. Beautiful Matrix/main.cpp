#include <iostream>

using namespace std;
int a[5][5];
int main()
{
    int x,y;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cin>>a[i][j];
            if(a[i][j]==1)
            {
                y=i;
                x=j;
            }
        }
    }
    int ans=0;
    if(x>2)
        ans+=x-2;
    else
        ans+=2-x;
    if(y>2)
        ans+=y-2;
    else
        ans+=2-y;
    cout<<ans;
    return 0;
}
