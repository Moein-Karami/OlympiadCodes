#include <iostream>

using namespace std;

int main()
{
    int x , y;
    cin>> x ;
    int n[x+1];
    string m[x+1];

    for (int i=1 ; i<=x ; i++)
    {
        cin>>m[i];;
    }
    for (int i=1;i<=x;i++)
    {
       n[i]=m[i].size();
    }
    for(int i=1;i<=x;i++)
    {
        y=n[i]-1;
        if(n[i]>10)
        {
            cout<<m[i][1]<<n[i]-2<<m[i][y]<<endl;
        }
        else
            cout << m[i]<<endl;
    }
    return 0;
}
