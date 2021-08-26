#include <iostream>

using namespace std;
int a[3];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int p;
        cin>>p;
        if(p==25)
            a[0]++;
        if(p==50)
        {
            if(!a[0])
            {
                cout<<"NO";
                return 0;
            }
            a[1]++;
            a[0]--;
        }
        if(p==100)
        {
            if(!a[0])
            {
                cout<<"NO";
                return 0;
            }
            if(!a[1]&&a[0]<3)
            {
                cout<<"NO";
                return 0;
            }
            if(a[0]&&a[1])
            {
                a[2]++;
                a[1]--;
                a[0]--;
            }
            else
                a[0]-=3;
        }
    }
    cout<<"YES";
    return 0;
}
