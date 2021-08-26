#include <iostream>

using namespace std;

int main()
{
    int ans=0;
    for(int i=0;i<=200;i++)
    {
        for(int j=0;j<=100;j++)
        {
            for(int q=0;q<=80;q++)
            {
                for(int w=0;w<=20;w++)
                {
                    for(int e=0;e<=10;e++)
                    {
                        for(int r=0;r<=4;r++)
                        {
                            for(int t=0;t<=2;t++)
                            {
                                if(i+j*2+q*5+w*10+e*20+r*50+t*100==200)
                                    ans++;
                                if(i+j*2+q*5+w*10+e*20+r*50+t*100>200)
                                {
                                    break;
                                }
                            }
                            if(i+j*2+q*5+w*10+e*20+r*50>200)
                            {
                                break;
                            }
                        }
                        if(i+j*2+q*5+w*10+e*20>200)
                        {
                            break;
                        }
                    }
                    if(i+j*2+q*5+w*10>200)
                    {
                        break;
                    }
                }
                if(i+j*2+q*5>200)
                {
                    break;
                }
            }
            if(i+j*2>200)
            {
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
