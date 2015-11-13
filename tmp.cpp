/*
ID: shh_nam1
LANG: C++
TASK: dualpal
*/
#include <iostream>
#include <cstdio>

using namespace std;

int change(int base,int num,int &len,int * store);
int check(int * store,int len);

int main()
{
    int b;
    scanf("%d",&b);
    int store[10000],len;
    for(int i=1; i<=300; i++)
    {
        change(b,i*i,len,store);
        if(check(store,len)==1)
        {
            if(b<=10)
            {
                printf("%d ",i);
                for(int j=len-1; j>=0; j--)
                {
                    printf("%d",store[j]);
                }
            }
            else
            {
                int tmp[10000],tlen;
                change(b,i,tlen,tmp);
                for(int j=tlen-1; j>=0; j--)
                {
                    char use1='A';
                    if(tmp[j]>10)
                        cout<<(char)(use1+tmp[j]-11);
                    else
                        printf("%d",tmp[j]);
                }
                printf(" ");
                for(int j=len-1; j>=0; j--)
                {
                    char use1='A';
                    if(tmp[j]>10)
                        cout<<(char)(use1+tmp[j]-11);
                    else
                        printf("%d",tmp[j]);
                }
            }
            printf("\n");
        }
    }

    return 0;
}

int change(int base,int num,int &len,int * store)
{
    len=0;
    while(num>=base)
    {
        store[len]=num%base;
        num/=base;
        len++;
    }
    store[len++]=num;
    return 0;
}

int check(int * store,int len)
{
    int flag=1;
    for(int i=0; i<len/2; i++)
    {
        if(store[i]!=store[len-i-1])
        {
            flag=0;
            break;
        }
    }
    if(flag)
        return 1;
    return -1;
}
