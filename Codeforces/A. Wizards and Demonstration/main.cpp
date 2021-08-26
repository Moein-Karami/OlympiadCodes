#include <iostream>

using namespace std;

int main()
{
    double n,y,x;
    cin>>n>>x>>y;
    double cnt=0;
    while((x+cnt)*100<y*n)
    {
        cnt++;
    }
    cout<<cnt;
    return 0;
}
