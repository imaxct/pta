#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
using namespace std;
#define INF 0x3f3f3f3f
#define CLR(x,y) memset(x,y,sizeof(x))
#define LC(x) (x<<1)
#define RC(x) ((x<<1)+1)
#define MID(x,y) ((x+y)>>1)
typedef pair<int,int> pii;
typedef pair<string,int>psi;
typedef long long LL;
const double PI=acos(-1.0);

const int N=210;

int d[N],pre[N],lib[N];
int val[N],sumval[N],vis[N];
int cnt;
int n,k,s,t,z,va,roads;
vector<pii>E[N];
map<string,int>myhash;
map<int,string>num;
string st,en,city,x,y;

void init(){
	CLR(d,INF);
	CLR(val,0);
	cnt=0;
	for (int i=0; i<N; ++i)
		E[i].clear();
	myhash.clear();
	num.clear();
	CLR(lib,0);
	CLR(sumval,0);
	CLR(pre,-1);	
	roads=0;
	CLR(vis,0);
}
void spfa(const int &s){
	int i;
	priority_queue<pii>Q;
	d[s]=0;
	lib[s]=0;
	sumval[s]=0;
	Q.push(pii(-d[s],s));
	while (!Q.empty())	{
		int now=Q.top().second;
		Q.pop();
		int SZ=E[now].size();
		for (i=0; i<SZ; ++i)		{
			int v=E[now][i].first;
			int w=E[now][i].second;
			if(d[v]>d[now]+w)			{
				d[v]=d[now]+w;
				sumval[v]=sumval[now]+val[v];
				pre[v]=now;
				lib[v]=lib[now]+1;
				Q.push(pii(-d[v],v));
			}else if(d[v]==d[now]+w&&lib[v]<lib[now]+1){
				sumval[v]=sumval[now]+val[v];		
				pre[v]=now;
				lib[v]=lib[now]+1;
			} else if(d[v]==d[now]+w&&lib[v]==lib[now]+1&&sumval[v]<sumval[now]+val[v]){
				sumval[v]=sumval[now]+val[v];		
				pre[v]=now;
				lib[v]=lib[now]+1;
			}
		}
	}
}
void dfs(int now){
	if(now==t)	{
		++roads;
		return ;
	}
	for (int i=0;i<E[now].size(); ++i)	{
		int v=E[now][i].first;
		int w=E[now][i].second;
		if(!vis[v]&&d[now]+w==d[v]){
			vis[v]=1;
			dfs(v);
			vis[v]=0;
		}
	}
}
int main(void){
	int i,j;
	while (cin>>n>>k>>st>>en){
		init();
		if(myhash.find(st)==myhash.end()){
			myhash.insert(psi(st,cnt));
			num[cnt]=st;
			++cnt;
		}
		for (i=0; i<n-1; ++i){
			cin>>city>>va;
			myhash[city]=cnt;
			val[cnt]=va;
			num[cnt]=city;
			++cnt;
		}
		for (i=0; i<k; ++i){
			cin>>x>>y>>z;
			int u=myhash[x],v=myhash[y];
			E[u].push_back(pii(v,z));
			E[v].push_back(pii(u,z));
		}
		s=myhash[st],t=myhash[en];
		spfa(s);
		int flag=0;
		stack<string>pos;
		for (int tpre=t; ~tpre; tpre=pre[tpre],flag++)
			pos.push(num[tpre]);
		while (!pos.empty()){
			--flag;
			printf("%s%s",pos.top().c_str(),flag?"->":"\n");
			pos.pop();
		}
		vis[s]=1;
		dfs(s);
		vis[s]=0;
		printf("%d %d %d\n",roads,d[t],sumval[t]);
	}
	return 0;
}