///DARK PROGRAMMER



#include <iostream>

using namespace std;
int k[4];
int m[4];
int main()
{
    for(int i=0;i<4;i++)
        m[i]=-1;
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(s[i]=='R')
            m[0]=i%4;
        if(s[i]=='B')
            m[1]=i%4;
        if(s[i]=='Y')
            m[2]=i%4;
        if(s[i]=='G')
            m[3]=i%4;
    }
    for(int j=0;j<4;j++)
    {
        if(m[j]==-1)
        {
            bool b=1;
            for(int i=0;i<n;i++)
            {
                if(s[i]=='!')
                {
                    for(int y=0;y<4;y++)
                        if(i%4==m[y])
                            b=0;
                    if(b)
                    {
                        m[j]=i%4;
                    }
                }

            }
        }
    }

    for(int i=0;i<n;i++)
    {
        if(s[i]=='!')
        {
            if(i%4==m[0])
                k[0]++;
            if(i%4==m[1])
                k[1]++;
            if(i%4==m[2])
                k[2]++;
            if(i%4==m[3])
                k[3]++;
        }
    }
    cout<<k[0]<<" "<<k[1]<<" "<<k[2]<<" "<<k[3];
    return 0;
}
