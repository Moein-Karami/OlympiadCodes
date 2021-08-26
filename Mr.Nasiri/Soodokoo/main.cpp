///DARK PROGRAMMER



#include <bits/stdc++.h>

using namespace std;
int jadval[10][10];
bool check[10];
void khali()
{
    for(int i=0;i<=9;i++)
        check[i]=0;
}
bool hal(int x,int y)
{
    int tmp=0;
    int t1,t2;
    bool ans=0,c=0;
    int counter=0;
    ///DEBUG
    for(int i=1;i<=9;i++)
    {
        khali();
        for(int j=1;j<=9;j++)
        {
            if(jadval[i][j])
            {
                if(check[jadval[i][j]])
                {

                    jadval[x][y]=0;
                     return 0;
                }
                check[jadval[i][j]]=1;
            }
        }
    }
    for(int i=1;i<=9;i++)
    {
        khali();
        for(int j=1;j<=9;j++)
        {
            if(jadval[j][i])
            {
                if(check[jadval[j][i]])
                {
                    jadval[x][y]=0;
                     return 0;
                }
                check[jadval[j][i]]=1;
            }
        }
    }
    for(int q=0;q<=6;q+=3)
    {
        for(int w=0;w<=6;w+=3)
        {
            khali();
            tmp=0;
            for(int i=1;i<=3;i++)
            {
                for(int j=1;j<=3;j++)
                {
                    if(jadval[i+q][j+w])
                    {
                        tmp++;
                        if(check[jadval[i+q][j+w]])
                        {
                            jadval[x][y]=0;
                            return 0;
                        }
                        check[jadval[i+q][j+w]]=1;
                    }
                }
            }
        }
    }
    ///

    for(int i=1;i<=9;i++)
        for(int j=1;j<=9;j++)
            if(jadval[i][j]==0)
                counter++;
    if(counter==0)
    {
        return 1;
    }
    ///Shit
    khali();
    bool b=0;
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            khali();
            if(jadval[i][j]==0)
            {
                for(int q=1;q<=9;q++)
                {
                    khali();
                    for(int w=1;w<=9;w++)
                    {
                        check[jadval[i][w]]=1;
                        check[jadval[w][j]]=1;
                    }
                    if(!check[q])
                    {
                        jadval[i][j]=q;
                        ans=hal(i,j);
                        b=max(b,ans);
                        if(ans)
                            return 1;
                    }
                }
                if(!b)
                {
                    jadval[x][y]=0;
                    return 0;
                }
            }
        }
    }
    ///
    if(!ans)
        jadval[x][y]=0;
    return ans;
}
char ch[10][10];
int main()
{
    for(int i=1;i<=9;i++)
        for(int j=1;j<=9;j++)
            cin>>ch[i][j];
    for(int i=1;i<=9;i++)
        for(int j=1;j<=9;j++)
            jadval[i][j]=ch[i][j]-'0';
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(jadval[i][j]==0)
            {
                hal(i,j);
                i=10;
                j=i;
            }
        }
    }
    for(int i=1;i<=9;i++)
    {
         for(int j=1;j<=9;j++)
            cout<<jadval[i][j]<<" ";
         cout<<endl;
    }

    return 0;
}
