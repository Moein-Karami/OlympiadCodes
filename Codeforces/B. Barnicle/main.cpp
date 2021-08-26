#include <iostream>
#include <string>

using namespace std;
char a[1000],tmp;
long long int n,cnt,p,cnt2;
long double ans,x;
void noghte(int);
string str;
void e(int);
int main()
{
    for(int i=0;i<1000;i++)
        a[i]='0';
    cin>>str;
    n=str.size();
    for(int i=0;i<n;i++)
    {
        if(str[i]!='.'&&str[i]!='e')
        {
            a[cnt]=str[i];
            cnt++;
        }
        else if(str[i]=='.')
        {
            p=i;
            a[cnt]=str[i];
            cnt++;
            noghte(i);
            i=n;
        }
        else if(str[i]=='e')
        {
            e(i);
            i=n;
        }
    }
    for(int i=p;i<cnt;i++)
        if(a[i]=='0')
        cnt2++;
    if(cnt2!=cnt-p-1)
    {
        for(int i=0;i<cnt;i++)
        {
            if(i!=cnt-1)
            cout<<a[i];
            else
            {
                if(a[i]!='.')
                    cout<<a[i];
            }

        }
    }
    else
    {
    for(int i=0;i<p;i++)
        {
            if(i!=cnt-1)
            cout<<a[i];
            else
            {
                if(a[i]!='.')
                    cout<<a[i];
            }

        }
    }

}
void noghte(int i)
{
    double q;
   for(int j=i+1;j<n;j++)
   {
       if(str[j]!='e')
       {
           a[cnt]=str[j];
           cnt++;
       }
       else
       {
           e(j);
           j=n;
       }

   }
}
void e(int i)
{
    for(int j=i+1;j<n;j++)
   {
           x=x*10+(str[j]-48);
   }
   while(x--)
   {
       a[p]=a[p+1];
       a[p+1]='.';
       p++;
       if(p>=cnt)
        cnt++;
   }
}
