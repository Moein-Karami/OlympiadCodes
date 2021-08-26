#include <iostream>

using namespace std;
bool b[200];
double n;
int a[200];
bool check(int);
int main()


{
    for(int i=60;i<180;i++)
    {
        if(check(i))
        {
            b[i]=true;
        }
    }
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
        if(b[a[i]])
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
bool check(int i)
{
    double n=360;
    double s=180-i;
    n=n/s;
    n*=1000;
    int a=n;
    if(a%1000==0)
        return true;
    else
        return false;
}
