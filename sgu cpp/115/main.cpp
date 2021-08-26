#include <iostream>

using namespace std;

int main()
{
    int m , d , x , y ;
    cin >>d>>m ;
    if(m==1)
        x=0;
    else if(m==2)
        x=31;
    else if(m==3)
        x=59;
    else if(m==4)
        x=90;
    else if(m==5)
        x=120;
    else if(m==6)
        x=151;
    else if(m==7)
        x=181;
    else if(m==8)
        x=212;
    else if(m==9)
        x=243;
    else if(m==10)
        x=273;
    else if(m==11)
        x=304;
    else if(m==12)
        x=334;
    y=(x+d)%7;
    if(y==0)
        cout<<"7";
    else
        cout<<y;

    return 0;
}
