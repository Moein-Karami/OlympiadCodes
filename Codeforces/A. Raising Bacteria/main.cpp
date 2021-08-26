#include <iostream>

using namespace std;

int main()
{
    int x;
    cin>>x;
    int cnt=0;
    while(x>0)
    {
        if(x%2==0)
            x/=2;
        else
        {
            x--;
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
