#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int n=s.size();
    bool b=1;
    while(b)
    {
        int cnt=1;
        b=0;
        for(int i=0 ;i<n;i++)
        {
            cnt=1;
            while(s[i]==s[i+1])
            {
                cnt++;
                i++;
            }
            if(cnt>=3)
            {
                //cout<<i<<" "<<cnt<<endl;
                s.erase(i-cnt+1,cnt);
                n=s.size();
                b=1;
                //cout<<s<<endl;
                i=i-cnt;
            }
        }
    }
    n=s.size();
    if(n)
    cout<<s;
    else
        cout<<"null";
    return 0;
}
