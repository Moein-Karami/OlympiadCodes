#include <iostream>
#include <string>
using namespace std;
long long int t[100000+10];
bool b[100000+10];
int main()
{
    long long int n,c=1;
    cin>>n;
    string str;
    cin>>str;
    for(int i=0;i<n;i++)
        cin>>t[i];
    long long int i=0;
    while(c=1)
    {
        if(b[i]!=0)
        {
            cout<<"INFINITE";
            return 0;
        }
        b[i]=1;
        if(str[i]=='>')
            i+=t[i];
        else
            i-=t[i];
        if(i>=n||i<0)
        {
           cout<<"FINITE";
           return 0;
        }


    }
    return 0;
}
