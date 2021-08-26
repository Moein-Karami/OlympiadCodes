#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin>>str;
    int s=str.size();
    int cnt=0;
    for(int i=0;i<s;i++)
    {
        if(cnt==6)
        {
            cout<<"YES";
            return 0;
        }
        if(str[i]==str[i+1])
            cnt++;
        else
            cnt=0;
    }
    cout<<"NO";
    return 0;
}
