///DARK PROGRAMMER

#include <iostream>

using namespace std;

int main()
{
    int a[5];
    for(int i=1;i<=4;i++)
        cin>>a[i];
    string s;
    cin>>s;
    int n=s.size();
    int sum=0;
    for(int i=0;i<n;i++)
    {
       sum+=a[s[i]-48];
    }
    cout<<sum;
    return 0;
}
