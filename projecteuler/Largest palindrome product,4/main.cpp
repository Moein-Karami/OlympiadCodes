#include <iostream>

using namespace std;
int y,c,w;
int main()
{
    for(int i=999;i>=100;i--)
    {
        for(int j=999;j>99;j--)
        {
            if((i*j)/100000!=0)
            {
                int x=i*j;
                if(x/100000==x%10&&(x/10000)%10==(x%100)/10&&(x/1000)%10==(x%1000)/100)
                {
                    if(x>y)
                    {
                        y=x;
                        c=i;
                        w=j;
                    }
                }
            }

        }
    }
    cout<<y;
    return 0;
}
