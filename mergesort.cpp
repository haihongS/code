#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

struct II
{
    int num,score,classs;
} stu[1000];

int mergeit(int lt,int mid,int rt);
int mergesort(int lt,int rt);

int main()
{
    srand((unsigned)time(0));
    int loca=0;
    int m,n;
    printf("请输入班级个数: ");
    scanf("%d",&m);
    printf("请输入每个班最多学生个数： ");
    scanf("%d",&n);
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            stu[loca].classs=i;
            stu[loca].num=i*100+j;
            stu[loca].score=rand()%51+50;
            loca++;
        }
    }
    for(int i=0;i<m;i++)
    {
        mergesort(i*n,i*n+n-1);
        printf("\n%d班成绩\n",i+1);
        printf("学号 班级 成绩\n");
        for(int j=i*n;j<i*n+n;j++)
            cout<<stu[j].num<<"   "<<stu[j].classs<<"    "<<stu[j].score<<endl;

    }
    printf("\n全校排名\n");
    printf("学号 班级 成绩\n");
    mergesort(0,loca-1);
    for(int i=0;i<loca;i++)
        cout<<stu[i].num<<"   "<<stu[i].classs<<"    "<<stu[i].score<<endl;

    return 0;
}

int mergesort(int lt,int rt)
{
    if(lt<rt)
    {
        int mid=(lt+rt)/2;
        mergesort(lt,mid);
        mergesort(mid+1,rt);
        mergeit(lt,mid,rt);
    }
    return 0;
}

int mergeit(int lt,int mid,int rt)
{
    II tmp[1000];
    int tloca=0,i=lt,j=mid+1;
    while(i<=mid && j<=rt)
    {
        if(stu[i].score>=stu[j].score)
            tmp[tloca++]=stu[i++];
        else
            tmp[tloca++]=stu[j++];
    }
    while(i<=mid)
        tmp[tloca++]=stu[i++];
    while(j<=rt)
        tmp[tloca++]=stu[j++];
    for(int i=0; i<tloca; i++)
        stu[lt+i]=tmp[i];
    return 0;
}
