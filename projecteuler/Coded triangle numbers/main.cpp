///DARK PROGRAMMER



#include <bits/stdc++.h>

using namespace std;
int tra[410],ans;
char ch[20];
int main()
{
    for(int i=1;i<=400;i++)
        tra[i]=(i*(i+1))/2;
    bool b=1;
    while(b)
    {
        int i=1;
        char c;
        cin>>c;
        if(c=='"')
        {
            cin>>ch[i];
            while(ch[i-1]!='"')
            {
                i++;
                cin>>ch[i];

            }
            int a=0;
            for(int j=1;j<i;j++)
                a+=ch[j];
            bool r=0;
            for(int j=1;j<=400;j++)
                if(a==tra[j])
                    r=1;
            if(r)
                ans++;
            cout<<ans<<endl;
        }
    }
    return 0;
}
