#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int siz;
    siz=s.size();
    int cntd=0,cnta=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='D')
        {
            cntd++;
        }
        else
        {
            cnta++;
        }
    }
    if(cnta>cntd)
    {
        cout<<"Anton";
    }
    else if (cntd>cnta)
        cout<<"Danik";
    else if(cnta==cntd)
        cout<<"Friendship";
    return 0;
}
