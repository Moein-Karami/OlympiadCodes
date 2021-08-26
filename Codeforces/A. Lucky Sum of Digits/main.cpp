#include <iostream>

using namespace std;

int main()
{
    int cnt=0,cnt4=0,cnt7=0;
    bool b=0;
    int n;
    cin>>n;
    while(cnt*4<=n)
    {
       if((n-(cnt*4))%7==0)
       {
           cnt7=(n-(cnt*4))/7;
           b=1;
           cnt4=cnt;
           cnt=n+1;
       }
       else
        cnt++;
    }
    if(b)
    {
        for(int i=1;i<=cnt4;i++)
        cout<<4;
    for(int i=1;i<=cnt7;i++)
        cout<<7;
    }
    else
        cout<<-1;
    return 0;
}
