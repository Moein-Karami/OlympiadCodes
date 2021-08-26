#include <iostream>
#include <iostream>
using namespace std;

int main()
{
    int n,cnt=0;
    cin>>n;
    string str;
    cin>>str;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='o'&&str[i+1]=='g'&&str[i+2]=='o')
        {
            cnt++;
            i++;
        }
        else
        {
            if(cnt>=1)
            {
              cout<<"***";
            }
            else
                cout<<str[i];
            cnt=0;
        }
    }
    return 0;
}
