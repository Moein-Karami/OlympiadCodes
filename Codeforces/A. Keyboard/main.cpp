#include <iostream>

using namespace std;

int main()
{
    char p;
    cin>>p;
    string v,a,b,c;
    cin>>v;
    a="qwertyuiop";
    b="asdfghjkl;";
    c="zxcvbnm,./";
    int n=v.size();
    if(p=='R')
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(a[j]==v[i])
                    cout<<a[j-1];
                if(b[j]==v[i])
                    cout<<b[j-1];
                if(c[j]==v[i])
                    cout<<c[j-1];
            }
        }
    }
    else
    {
       for(int i=0;i<n;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(a[j]==v[i])
                    cout<<a[j+1];
                if(b[j]==v[i])
                    cout<<b[j+1];
                if(c[j]==v[i])
                    cout<<c[j+1];
            }
        }
    }
    return 0;
}
