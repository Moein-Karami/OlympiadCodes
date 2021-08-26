#include <iostream>

using namespace std;

int main()
{
    long long unsigned int pool,bot,glas,sood,cnt=0;
    cin>>pool>>bot>>glas>>sood;
    long long unsigned int x;
    if(glas-sood<=bot&&pool>=glas)
    {
        pool-=(glas-1);
        x=glas-sood;
        cnt+=(pool/x);
        pool+=(glas-1);
        pool-=(x*cnt);
        while(pool>=glas)
        {
            pool=pool-glas+sood;
            cnt++;
        }
            cnt+=(pool/bot);
    }
    else
    {
        cnt+=pool/bot;
        pool-=(cnt*bot);
      while(pool>=bot)
        {
          pool=pool-bot;
          cnt++;
        }
        while(pool>=glas)
        {
            pool=pool-glas+sood;
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
