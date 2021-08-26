#include <iostream>

using namespace std;

int main()
{
    int x1 , x2 , y1 , y2 , z1 , z2  , t1 , t2 ,t3,s;
    cin >> x1 >> y1>>z1 ;
    cin >> x2 >> y2 >> z2;
    t1=x1/x2;
    t2=y1/y2;
    t3=z1/z2;
    if(t1>t2)
        s=t2;
    else
        s=t1;
    if (t3<s)
        s=t3;
    cout << s;
    return 0;
}
