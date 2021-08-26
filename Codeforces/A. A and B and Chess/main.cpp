#include <iostream>

using namespace std;

int main()
{
    int q=9,r=5,b=3,n=3,p=1,cntw=0,cntb=0;
    string s[8];
    for(int i=0;i<8;i++)
    {

        cin>>s[i];

    }
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(s[i][j]!='.'&&s[i][j]<='Z')
            {
                if(s[i][j]=='Q')
                    cntw+=q;
                if(s[i][j]=='R')
                    cntw+=r;
                    if(s[i][j]=='B')
                    cntw+=b;
                    if(s[i][j]=='N')
                    cntw+=n;
                    if(s[i][j]=='P')
                    cntw+=p;
            }
            if(s[i][j]!='.'&&s[i][j]>'Z'&&s[i][j]>='a')
            {
                if(s[i][j]=='q')
                    cntb+=q;
                if(s[i][j]=='r')
                    cntb+=r;
                    if(s[i][j]=='b')
                    cntb+=b;
                    if(s[i][j]=='n')
                    cntb+=n;
                    if(s[i][j]=='p')
                    cntb+=p;
            }
        }
    }
    if(cntw>cntb)
        cout<<"White";
    if(cntb>cntw)
        cout<<"Black";
    if(cntb==cntw)
        cout<<"Draw";
    return 0;
}
