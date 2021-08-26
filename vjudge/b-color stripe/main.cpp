#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n , x , cnt=0 , cnt2=0,o=0;
    cin>>n>>x;
    string st;
    cin>>st;
    if(x==2)
    {
        for (int i=0 ; i<n;i++)
        {
            if(i%2==0&&st[i]!='A')
            {
                cnt++;
            }
            if(i%2!=0&&st[i]!='B')
            {
                cnt++;
            }
            if(i%2==0&&st[i]!='B')
            {
                cnt2++;
            }
            if(i%2!=0&&st[i]!='A')
            {
                cnt2++;
            }
        }
            o=min(cnt,cnt2);
            cout<<o<<endl;
            if(o==cnt2)
            {
                    for(int i=0;i<n;i++)
                {
                    if(i%2==0)
                        cout<<"B";
                    else
                        cout<<"A";
                }
            }
            else if(o==cnt)
            {
                for(int i=0;i<n;i++)
                {
                    if(i%2==0)
                        cout<<"A";


                    else
                        cout<<"B";
                }
            }

    }
    else
    {
        for(int i=1;i<n;i++)
        {
            if(st[i]==st[i-1])
            {
                o++;
                if(st[i+1]!='B'&&st[i]!='B')
                {
                    st[i]='B';
                }
                else if(st[i+1]!='A'&&st[i]!='A')
                {
                    st[i]='A';
                }
                else if(st[i+1]!='C'&&st[i]!='C')
                {
                    st[i]='C';
                }


            }
        }
        cout<<o<<endl<<st;

    }
    return 0;
}
