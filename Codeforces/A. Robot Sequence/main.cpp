#include <iostream>
#include <string>
using namespace std;
int o=0,a=0,cnt=0;
int main()
{
    string str;
    int n;
    cin>>n;
    cin>>str;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(str[j]=='R')
                o++;
            if(str[j]=='L')
                o--;
            if(str[j]=='U')
                a++;
            if(str[j]=='D')
                a--;
            if(o==0&&a==0)
                cnt++;
        }
        o=0;
        a=0;
    }
    cout<<cnt;
    return 0;
}
