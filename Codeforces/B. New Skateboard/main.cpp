#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int n=s.size(),ans=0;
    for(int i=0;i<n;i++)
    {
        if((s[i]-48)%4==0)
            ans++;
       if((((s[i]-48)*10)+(s[i+1]-48))%4==0)
       {
           ans+=i+1;
           cout<<i+1<<endl;
       }
    }
    cout<<ans;
    return 0;
}
