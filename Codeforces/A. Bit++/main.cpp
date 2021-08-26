#include <iostream>
#include <string>
using namespace std;

int main()
{
    int x=0,n,cnt1,cnt2;
    cin>>n;
    string str[n];
    for(int i=0;i<n;i++)
    {
        cin>>str[i];
    }
    for(int i=0;i<n;i++)
    {
        cnt1=0;
        cnt2=0;
        for(int j=0;j<=2;j++)
        {
            if(str[i][j]=='+')
                cnt1++;
            else if(str[i][j]=='-')
                cnt2++;
        }
        if(cnt1==2)
            x++;
        else if(cnt2==2)
            x--;
    }
    cout<<x;
    return 0;
}
