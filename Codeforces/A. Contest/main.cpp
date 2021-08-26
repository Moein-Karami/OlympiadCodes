#include <iostream>

using namespace std;

int main()
{
    int a,b,ta,tb;
    cin>>a>>b>>ta>>tb;
    int m=max(3*(a/10),a-((a/250)*ta));
    int v=max(3*(b/10),b-((b/250)*tb));
    if(m>v)
        cout<<"Misha";
    else if(v>m)
        cout<<"Vasya";
    else
        cout<<"Tie";
    return 0;
}
