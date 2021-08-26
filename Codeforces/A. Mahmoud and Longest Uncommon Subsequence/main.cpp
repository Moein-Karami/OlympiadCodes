///DARK PROGRAMMER



#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string a , b;
    cin>>a>>b;
    int n=max(a.size(),b.size());
    if(a.size()==0||b.size()==0)
    {
        cout<<-1;
        return 0;
    }
    while(a==b&&n)
    {
        n--;
        a.erase(n,1);
        b.erase(n,1);
    }
    if(!n)
        n--;
    cout<<n;
    return 0;
}
