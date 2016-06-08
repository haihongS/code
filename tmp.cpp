#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <utility>

using namespace std;
const int maxn=2e5+9;
const int inf=2e9+9;

int n,m,c;
vector<int> aha[maxn];

struct edge
{
	int to,cost;
};

typedef pair<int,int> P;

vector<edge> G[maxn];
int d[maxn];

void Dijkstra();

int main()
{
	int t;
	scanf("%d",&t);
	int cass=1;
	while(t--)
	{
		for(int i=0;i<maxn;i++)
		{
			aha[i].clear();
			G[i].clear();
			d[i]=inf;
		}
		scanf("%d%d%d",&n,&m,&c);
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			aha[x].push_back(i);
		}
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<aha[i].size();j++)
			{
				for(int k=0;k<aha[i+1].size();k++)
				{
					int x=aha[i][j],y=aha[i][k];
					edge tmp={y,c};
					G[x].push_back(tmp);
					tmp.to=x;
					G[y].push_back(tmp);
				}
			}
		}
		for(int i=0;i<aha[1].size();i++)
		{
			for(int j=0;j<aha[n].size();j++)
			{
				int x=aha[1][i],y=aha[n][j];
				edge tmp={y,c};
				G[x].push_back(tmp);
				tmp.to=x;
				G[y].push_back(tmp);
			}
		}
		
		for(int i=0;i<n;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			edge tmp;
			tmp.cost=w,tmp.to=v;
			G[u].push_back(tmp);
			tmp.to=u;
			G[v].push_back(tmp);
		}


		printf("Case #%d: ",cass++);
		Dijkstra();
		if(d[n]==inf)
			printf("-1\n");
		else
			printf("%d\n",d[n]);
	}
	return 0;
}

void Dijkstra()
{
	d[1]=0;
	priority_queue<P ,vector<P> ,greater<P> > go;
	while(!go.empty()) go.pop();
	go.push(P(0,1));

	while(!go.empty())
	{
		P tp=go.top();go.pop();	
		int v=tp.second;
		if(d[v]<tp.first) continue;
		for(int i=0;i<G[v].size();i++)
		{
			edge next=G[v][i];
			if(d[next.to]>d[v]+next.cost)
			{
				d[next.to]=d[v]+next.cost;
				go.push(P(d[next.to],next.to));
			}
		}
	}
}

