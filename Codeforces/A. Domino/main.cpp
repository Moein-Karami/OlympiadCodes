///DARK PROGRAMMER



#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int b[n],p[n];
    for(int i=0;i<n;i++)
        cin>>b[i]>>p[i];
    int bs=0,ps=0;
    for(int i=0;i<n;i++)
    {
        bs+=b[i];
        ps+=p[i];
    }
    if(bs%2==0&&ps%2==0)
    {
        cout<<0;
        return 0;
    }
    else if(bs%2!=ps%2)
    {
        cout<<-1;
        return 0;
    }
    else if(bs%2==1&&ps%2==1)
    {
        bool c=0;
        for(int i=0;i<n;i++)
        {
            if(b[i]%2!=p[i]%2)
            {
                cout<<1;
                return 0;
            }
        }
    }
    cout<<-1;
    return 0;
}
