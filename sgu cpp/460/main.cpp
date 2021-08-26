#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n , x;
    cin >> n ;
    string a[n];
    for(int i=0 ; i<n ; i++)
        cin>>a[i];
    for(int i=0 ; i<n ; i++)
    {
        x=a[i].length();
        if(a[i][x-1]=='x'||a[i][x-1]=='s'||a[i][x-1]=='o')
        {
         cout<<a[i]<<"es"<<endl;
        }
        else if(a[i][x-2]=='c'&&a[i][x-1]=='h')
        {
            cout<<a[i]<<"es"<<endl;
        }
        else if(a[i][x-1]=='f')
        {
            a[i][x-1]='v';
            cout<<a[i]<<"es"<<endl;
        }

        else if (a[i][x-2]=='f'&&a[i][x-1]=='e')
        {
            a[i][x-2]='v';
            a[i][x-1]='e';
            cout<<a[i]<<"s"<<endl;
        }
        else if(a[i][x-1]=='y')
        {
            a[i][x-1]='i';
            cout<<a[i]<<"es"<<endl;
        }

        else
            cout<<a[i]<<"s"<<endl;
    }

    return 0;
}
