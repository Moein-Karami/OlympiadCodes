#include <iostream>
#include <string>

using namespace std;

int main()
{
    char z='x',y='X';
    int n;
    cin>>n;
    string str;
    cin>>str;
    int x=n/2,cnt=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='x')
            cnt++;
    }
    if(cnt>x)
    {
        cnt=n-cnt;
        z='X';
        y='x';
    }

    if(cnt==n-cnt)
    {
        cout<<0;
    }
    else if(cnt<n-cnt)
    {
     cout<<x-cnt;
     int s=x-cnt;
     int i=0;
     while(s>0)
     {

         if(str[i]==y)
         {
            str[i]=z;
            s--;
         }
         i++;
     }

    }

    else if(cnt>n-cnt)
    {
     cout<<n-(x-cnt);
     int s=n-(x-cnt);
     int i=0;
     while(s>0)
     {

         if(str[i]==z)
         {
            str[i]=y;
            s--;
         }
         i++;
     }

    }
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<str[i];
    return 0;
}
