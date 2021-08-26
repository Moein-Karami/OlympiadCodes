#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    if(x1-x2==0)
    {
        cout<<fabs(y1-y2)+x1<<" "<<y1<<" "<<fabs(y1-y2)+x1<<" "<<y2;
    }
    else if(y1-y2==0)
    {
        cout<<x1<<" "<<fabs(x1-x2)+y1<<" "<<x2<<" "<<fabs(x1-x2)+y2;
    }
    else if(fabs(x1-x2)==fabs(y1-y2))
    {
        cout<<x1<<" "<<y2<<" "<<x2<<" "<<y1;
    }
    else
        cout<<-1;
    return 0;
}
