/* ***********************************************
Author        :shootPlane
Created Time  :2016/2/25 19:56:39
File Name     :S:\01\main.cpp
Blog          :http://haihongblog.com
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <stack>
using namespace std;
typedef long long LL;
const int maxn=1e5+9;
const int inf=1e9+9;

int m,n;
int mapp[20][20];
int flag[20][20];
int endit[20][20];

int check(int len);
int deal();
int output();

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	while(~scanf("%d%d",&m,&n))
	{
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&mapp[i][j]);
		int up=1<<n;
		int gg=0;
		for(int i=0;i<up;i++)
		{
			int tt=i;
			int loca=n-1;
			memset(flag,0,sizeof(flag));
			while(tt)
			{
				endit[0][loca--]=tt&1;
				tt>>=1;
			}
			check(0);
			if(deal()==-1)
				continue;
			else
			{
				gg=1;
				output();
				break;
			}
		}
		if(gg==0)
			printf("IMPOSSIBLE\n");
	}
    return 0;
}

int deal()
{
	for(int i=1;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(flag[i-1][j]%2==1)
            {
                endit[i][j]=1;
                //flag[i-1][j]=0;
            }
			else
                endit[i][j]=0;
		}
		check(i);
	}

	for(int i=0;i<n;i++)
		if(flag[m-1][i]%2==1)
			return -1;
	return 0;
}

int check(int len) // len--hang
{
	for(int i=0;i<n;i++)
	{
		int tmp=0;
		if(i>0)
        {
            if(endit[len][i-1]%2!=0)
                tmp++;
        }
        if(i<n-1)
        {
            if(endit[len][i+1]%2!=0)
                tmp++;
        }
		if(len>0)
        {
            if(endit[len-1][i]%2==1)
                tmp++;
        }
        tmp+=mapp[len][i];
        tmp+=endit[len][i];
		flag[len][i]=tmp%2;
	}
	return 0;
}

int output()
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j==0)
				printf("%d",endit[i][j]%2);
			else
				printf(" %d",endit[i][j]%2);
		}
		printf("\n");
	}
	return 0;
}
