#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if((s[i]-48)%8==0)
        {
            cout<<"YES"<<endl<<s[i];
            i=n;
            return 0;
        }
        for(int j=i+1;j<n;j++)
        {
            if(((10*(s[i]-48))+s[j]-48)%8==0)
            {
                cout<<"YES"<<endl<<s[i]<<s[j];
                i=n;
                j=i;
                return 0;
            }
            for(int q=j+1;q<n;q++)
            {
                    if(((10*((10*(s[i]-48))+s[j]-48))+s[q]-48)%8==0)
                {
                    cout<<"YES"<<endl<<s[i]<<s[j]<<s[q];
                    i=n;
                    j=i;
                    q=j;
                    return 0;
                }
            }
        }
    }
    cout<<"NO";
    return 0;
}
