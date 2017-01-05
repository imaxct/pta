#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cstring>
#define MAXN 510
#define MAXM 252000
using namespace std;
const int inf = 0x3f3f3f3f;
struct edge{
	int v,w, c;
	edge *next;
	void add(int x,int y,edge *&head, int cost){
		v=x,w=y,next=head,head=this, c = cost;
	}
}*head[MAXN],Te[MAXM*2],*p=Te;
void add_edge(int x,int y,int z, int cost){
	p++->add(y,z,head[x], cost);
}
int n,m,s,t;

bool visit[MAXN];
int cnt[MAXN];
int dist[MAXN];
int cost[MAXN];
bool spfa(int x){
	queue<int>q;
	memset(visit,0,sizeof(visit));
	memset(dist,0x3f,sizeof(dist));
	memset(cost, 0x3f, sizeof(cost));
	q.push(x);
	dist[x]=0;
	cost[x] = 0;
	cnt[x]++;
	visit[x]=true;
	while(!q.empty()){
		int tmp=q.front();
		q.pop();visit[tmp]=false;
		for(edge *p=head[tmp];p;p=p->next){
			if (dist[p->v] == dist[tmp] + p->w)
				if (cost[p->v] > cost[tmp] + p->c)
					cost[p->v] = cost[tmp] + p->c;
				if (dist[p->v] > dist[tmp] + p->w){
					dist[p->v]=dist[tmp]+p->w;
					cost[p->v] = cost[tmp] + p->c;
					if(!visit[p->v]){
						visit[p->v]=true;
						q.push(p->v);
					}
				}
		}
		
	}
	return true;
}
void init(){
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1,x,y,z,c;i<=m;i++){
		scanf("%d%d%d%d",&x,&y,&z, &c);
		add_edge(x+1,y+1,z,c);
		add_edge(y+1,x+1,z,c);
	}
}
int main(){
	init();
	if(!spfa(s+1))
		cout<<"error"<<endl;
	else
		cout<<dist[t+1] << ' ' << cost[t+1]<<endl;
}
