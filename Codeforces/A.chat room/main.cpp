#include <iostream>
#include <string>

using namespace std;

string x;
void chat(char);
bool y=1;
int j ,s;

int main()
{
    cin>>x;
    s=x.size();
    for (int i=1;i<=5;i++)
    {
        if (i==1)
            chat('h');
        if(y==0)
            i=6;

        if(i==2)
            chat('e');
        if(y==0)
            i=6;

        if(i==3||i==4)
            chat('l');
            if(y==0)
            i=6;

        if(i==5)
            chat('o');
            if(y==0)
            i=6;

    }
    if(y==1)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}

void chat(char v)
{
    bool c=0;
    for(int i=j ; i<s;i++)
    {
        if(x[i]==v)
        {
            j=i+1;
            c=1;
            i=100;
        }
    }
    if(c==0)
        y=0;

}
