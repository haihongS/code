#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>

typedef long long LL;

using namespace std;

struct II
{
    int head,tail;
}q[15];

int que[15][1000];
int num[1000];
LL powit[15];

int thenum(int x,int loca);
int lenNum(int x);

int main()
{
    powit[0]=1;
    for(int i=1;i<=11;i++)
        powit[i]=powit[i-1]*10;
    int n;
    memset(q,0,sizeof(q));
    printf("请输入元素个数: ");
    scanf("%d",&n);
    int len=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
        len=max(len,lenNum(num[i]));
    }
    for(int i=1;i<=len;i++)
    {
        for(int j=0;j<n;j++)
        {
            int tmpNum=thenum(num[j],i);
            que[tmpNum][q[tmpNum].tail++]=num[j];
        }
        int tmpLoca=0;
        for(int j=0;j<=9;j++)
        {
            while(q[j].tail!=q[j].head)
            {
                num[tmpLoca++]=que[j][q[j].head];
                q[j].head++;
            }
        }
    }
    for(int i=0;i<n;i++)
        printf("%d ",num[i]);
    return 0;
}

int thenum(int x,int loca)
{
    if(loca==1)
        return x%10;
    LL tmp=powit[loca];
    return x/(tmp/10)-x/tmp*10;
}

int lenNum(int x)
{
    int cnt=0;
    while(x>0)
    {
        cnt++;
        x/=10;
    }
    return cnt;
}
