#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    int s1=0,s2=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==0)
        {
            s1++;
        }
        else
            s2++;
    }
    if(s1==0)
    {
        cout<<-1;
        return 0;
    }
    if(s2<9)
    {
        cout<<0;
        return 0;
    }
    int t=s2/9;
    for(int i=1;i<=t;i++)
        for(int j=1;j<=9;j++)
            cout<<5;
    for(int i=1;i<=s1;i++)
        cout<<0;
    return 0;
}
