#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin>>str;
    int s=str.size();
    for(int i=0;i<s;i++)
    {
        if(str[i]!='o'&&str[i]!='O'&&str[i]!='a'&&str[i]!='A'&&str[i]!='e'&&str[i]!='E'&&str[i]!='i'&&str[i]!='I'&&str[i]!='u'&&str[i]!='U'&&str[i]!='y'&&str[i]!='Y')
        {
            cout<<".";
            if(str[i]<'a')
                str[i]+=32;
            cout<<str[i];
        }
    }
    return 0;
}
