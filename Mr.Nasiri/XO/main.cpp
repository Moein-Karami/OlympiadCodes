///DARK PROGRAMMER



#include <bits/stdc++.h>

using namespace std;
char xo[4][4];
bool check ()
{
    int tmp=0;
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            if(xo[i][j]=='.')
                tmp++;
    return tmp;
}
int winer()
{
    bool b1=1,b2=1;
    for(int i=1;i<=3;i++)
    {
        b1=1;
        b2=1;
        for(int j=2;j<=3;j++)
        {
            if(xo[i][j]=='.'||xo[i][j]!=xo[i][j-1])
                b1=0;
            if(xo[i][j]=='.'||xo[j][i]!=xo[j-1][i])
                b2=0;
        }
        if(b1)
        {
            if(xo[i][1]=='X')
                return 1;
            else
                return 2;
        }
        if(b2)
        {
            if(xo[1][i]=='X')
                return 1;
            else
                return 2;
        }
    }
    if(xo[1][1]!='.'&&xo[1][1]==xo[2][2]&&xo[1][1]==xo[3][3])
    {
        if(xo[1][1]=='X')
            return 1;
        else
            return 2;
    }
    if(xo[1][3]!='.'&&xo[1][3]==xo[2][2]&&xo[1][3]==xo[3][1])
    {
        if(xo[1][3]=='X')
            return 1;
        else
            return 2;
    }
    return 3;
}
int hal(int i)
{
    if(!check())
        return winer();
    if(winer()!=3)
        return winer();
    bool b[4];
    b[1]=0;
    b[2]=0;
    b[3]=0;
    if(i==1)
    {
        for(int j=1;j<=3;j++)
        {
            for(int q=1;q<=3;q++)
            {
                if(xo[j][q]=='.')
                {
                    xo[j][q]='X';
                    b[hal(3-i)]=1;
                    xo[j][q]='.';
                }
            }
        }
        if(b[1])
            return 1;
        if(b[3])
            return 3;
        return 2;
    }
    else
    {
        for(int j=1;j<=3;j++)
        {
            for(int q=1;q<=3;q++)
            {
                if(xo[j][q]=='.')
                {
                    xo[j][q]='0';
                    b[hal(3-i)]=1;
                    xo[j][q]='.';
                }
            }
        }
        if(b[2])
            return 2;
        if(b[3])
            return 3;
        return 1;
    }
}
bool check_again()
{
    int b1=1,b2=1,c1=0,c2=0;
    for(int i=1;i<=3;i++)
    {
        b1=1;
        b2=1;
        for(int j=2;j<=3;j++)
        {
            if(xo[i][j]=='.'||xo[i][j]!=xo[i][j-1])
                b1=0;
            if(xo[j][i]=='.'||xo[j][i]!=xo[j-1][i])
                b2=0;
        }
        if(b1)
        {
            if(xo[i][1]=='X')
                c1++;
            else
                c2++;
        }
        if(b2)
        {
            if(xo[1][i]=='X')
                c1++;
            else
                c2++;
        }
    }
    if(xo[1][1]!='.'&&xo[1][1]==xo[2][2]&&xo[1][1]==xo[3][3])
    {
        if(xo[1][1]=='X')
            c1++;
        else
            c2++;
    }
    if(xo[1][3]!='.'&&xo[1][3]==xo[2][2]&&xo[1][3]==xo[3][1])
    {
        if(xo[1][3]=='X')
            c1++;
        else
            c2++;
    }
    int a=0;
    if(c1&&c2)
        a=1;
    if(c1>1||c2>1)
        a=1;
    return a;
}
int main()
{
    int t=1;
    int x,o,ans;
    while(t)
    {
        x=0;
        o=0;
        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cin>>xo[i][j];
                if(xo[i][j]=='Q')
                    return 0;
                if(xo[i][j]=='X')
                    x++;
                if(xo[i][j]=='0')
                    o++;
            }
        }
        if(o>x||x>o+1||check_again())
        {

            cout<<"Illegal position."<<endl;
            continue ;
        }
        if(x==o+1&&winer()==2)
        {
            cout<<"Illegal position."<<endl;
            continue ;
        }
        if(x==o&&winer()==1)
        {
            cout<<"Illegal position."<<endl;
            continue ;
        }
        if(x==o)
            ans=hal(1);
        else
            ans=hal(2);
        if(ans==1)
            cout<<"X wins."<<endl;
        else if(ans==2)
            cout<<"0 wins."<<endl;
        else
            cout<<"Game is a draw."<<endl;
    }
    return 0;
}
