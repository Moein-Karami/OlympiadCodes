#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int n=s.size();
    int maxi=1;
    bool b=1;
    for(int i=0;i<n;i++)
    {
        int cnt=1;
        if(b)
        {
            //i--;
            b=0;
        }
        while(s[i]!='A'&&s[i]!='E'&&s[i]!='I'&&s[i]!='O'&&s[i]!='U'&&s[i]!='Y')
        {
            cnt++;
            i++;
            if(i==n)
                break;
        }
        //cout<<cnt<<" ";
        if(cnt>maxi)
            maxi=cnt;
        cnt=1;
    }
    cout<<endl<<maxi;
    return 0;
}
