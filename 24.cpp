#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <cstring>
#include <utility>
#define MAXN 1010
#define MAXM 10010
#define ll long long
using namespace std;
int n,m,s,t;
typedef pair<ll ,int> PII;
struct edge {
	int v;
	ll w;
	edge *next;
	void add(int y, ll z, edge *&head){ v = y; w = z; next = head; head = this; }
}*Pe,*head[MAXN];
void add_edge(int x, int y, ll z) {
	Pe=new edge;
	Pe->add(y, z, head[x]);
}

ll dist[MAXN];
bool visit[MAXN];

ll prim(int x) {
	ll ret=0;
	priority_queue<PII>q;
	while (!q.empty()) q.pop();
	memset(dist, 0x3f, sizeof(dist));
	memset(visit, 0, sizeof(visit));
	dist[x] = 0;
	q.push(make_pair(0, x));
	while (!q.empty()) {
		while (!q.empty() && visit[q.top().second]) q.pop();
		if (q.empty()) break;
		PII t = q.top(); q.pop();
		int i = t.second;
		dist[i] = -t.first;
		ret+=dist[i];
		visit[i]=true; 
		for (edge *p = head[i]; p; p = p->next)
			if (!visit[p->v]) q.push(make_pair(-p->w, p->v));
	}
	return ret;
} 
void init()
{
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add_edge(x,y,z);
        add_edge(y,x,z);		
	}
/*	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			int tmp;
			scanf("%d",&tmp);
			if(tmp!=0)
			{
				add_edge(i,j,tmp);
				add_edge(j,i,tmp);
			}
		}
		*/
}
int main()
{
	init();
	long ans = prim(1);
	for (int i=1; i<=n; ++i)
		if (!visit[i]){
			cout << -1 << endl;
			return 0;
		}
	cout << ans << endl;
	//cout<<prim(1)<<endl;
}


