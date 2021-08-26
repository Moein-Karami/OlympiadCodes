#include <iostream>

using namespace std;

int main()
{
    int a1,a2,cnt=0;
    cin>>a1>>a2;
    while(a1>0&&a2>0)
    {
        if(a1==1&&a2==1)
        break;
        else
        {
        if(a1>a2)
        {
            a1-=2;
            a2++;
        }
        else
        {
            a2-=2;
            a1++;
        }
        cnt++;
        }
    }


    cout<<cnt;
    return 0;
}
