#include <iostream>
#include <algorithm>
using namespace std;
int cnt[6];
int main()
{
    int a[6],cnt2=0;
    for(int i=0;i<6;i++)cin>>a[i];
    sort(a,a+6);
    for(int i=0;i<6;i++)
    {
        int cnt1=1;
        while(a[i]==a[i+1])
        {
            cnt1++;
            i++;
        }
        cnt[cnt2]=cnt1;
        cnt2++;
    }
    if(cnt[3]>0)
    {

        cout<< "Alien";
        return 0;
    }
    if(cnt[0]<4&&cnt[1]<4&&cnt[2]<4)
    {
        cout<< "Alien";
        return 0;
    }
    if(cnt[0]&&!cnt[1])
    {
        cout<<"Elephant";
        return 0;
    }
    if(cnt[1]&&!cnt[2])
    {
        if(cnt[0]==4||cnt[1]==2)
        {
            cout<<"Elephant";
            return 0;
        }
        if(cnt[0]==2||cnt[1]==4)
        {
            cout<<"Elephant";
            return 0;
        }
        if(cnt[0]==5||cnt[1]==1)
        {
            cout<<"Bear";
            return 0;
        }
        if(cnt[0]==1||cnt[1]==5)
        {
            cout<<"Bear";
            return 0;
        }
        cout<< "Alien";
        return 0;
    }
    if(cnt[0]!=4&&cnt[1]!=4&&cnt[2]!=4)
    {
        cout<< "Alien";
        return 0;
    }
    bool b=0,b1=0;
    for(int i=0;i<3;i++)
    {
        if(cnt[i]==1&&b)
            b1=1;
        if(cnt[i]==1)
            b=1;
    }
    if(b&&b1)
    {
        cout<<"Bear" ;
        return 0;
    }
    cout<< "Alien";
    return 0;
}
