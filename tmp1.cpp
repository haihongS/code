#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;
const int MAXSIZE=1e5+9;

int Mark[MAXSIZE];
int prime[MAXSIZE];

long long gcd(long long x,long long y);
long long Eular(long long x);
long long quickpow(long long m,long long n,long long k);
int Prime();

int main()
{
    int len=Prime();
    long long x,y,a0;
    while(~scanf("%lld%lld%lld",&x,&y,&a0))
    {
        long long lam=y/(1-x);
        if(lam==0)
        {
            printf("1\n");
            continue;
        }
        if(a0%lam==0)
        {
            printf("1\n");
            continue;
        }
        long long thegcd=gcd(abs(lam),abs(a0));
        a0/=thegcd;
        if(gcd(abs(a0),x)!=1)
        {
            printf("Impossible!\n");
            continue;
        }
        long long ans=Eular(abs(a0));
        a0=abs(a0);
        long long endit=sqrt(ans);
        long long flag=0;
        for(int i=0;i<len;i++)
        {
            if(prime[i]>endit)
                break;
            if(ans%prime[i]==0)
            {
                if(quickpow(x,prime[i],a0)==1)
                {
                    flag=prime[i];
                    break;
                }
            }
        }
        if(flag==0)
            printf("%lld\n",ans);
        else
            printf("%lld\n",flag);
    }

    return 0;
}

long long gcd(long long x,long long y)
{
    if(x<y)
        return gcd(y,x);
    if(y==0)
        return x;
    if(x&1)
    {
        if(y&1)
            return gcd(x-y,y);
        else
            return gcd(x,y>>1);
    }
    else
    {
        if(y&1)
            return gcd(x>>1,y);
        else
            return gcd(x>>1,y>>1)<<1;
    }
}

long long Eular( long long x)
{
    if( x == 0 ) return 0;
    long long res = 1, t = x;
    for(long long i = 2; i <= (long long)sqrt(1.*x); i++)
    {
        if( t%i == 0 )
        {
            res *= (i-1);
            t /= i;
            while( t%i ==0 )
            {
                res *= i;
                t /= i;
            }
        }
        if( t == 1 ) break;
    }
    if( t > 1 )
    {
        res *= (t-1);
    }
    return res;
}

long long quickpow(long long m,long long n,long long k)
{
    long long b = 1;
    while (n > 0)
    {
        if (n & 1)
            b = (b*m)%k;
        n = n >> 1 ;
        m = (m*m)%k;
    }
    return b;
}

int Prime()
{
    int index = 0;
    memset(Mark,0,sizeof(Mark));
    for(int i = 2; i < MAXSIZE; i++)
    {
        //如果未标记则得到一个素数
        if(Mark[i] == 0)
        {
            prime[index++] = i;
        }
        //标记目前得到的素数的i倍为非素数
        for(int j = 0; j < index && prime[j] * i < MAXSIZE; j++)
        {
            Mark[i * prime[j]] = 1;
            if(i % prime[j] == 0)
            {
                break;
            }
        }
    }
    return index;
}
