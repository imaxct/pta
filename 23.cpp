#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 110;
int p[maxn][maxn];
//int fa[maxn];
int n, m;
/*
int getfa(int x){
	return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
void merge(int x, int y){
	int fx = getfa(x),
		fy = getfa(y);
	if (fx != fy)
		fa[y] = fx;
}
*/
void floyd(){
	for (int k=1; k<=n; ++k)
		for (int i=1; i<=n; ++i)
			for (int j=1; j<=n; ++j)
				p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
}
void init(){
	cin >> n >> m;
	for (int i=1; i<=n; ++i){
		//fa[i] = i;
		for (int j=1; j<=n; ++j){
			p[i][j] = ((i==j)?0:0x3f3f3f3f);
		}
	}
	int u, v, w;
	for (int i=0; i<m; ++i){
		scanf("%d%d%d", &u, &v, &w);
		p[u][v] = p[v][u] = w;
	}
}
int main(){
	init();
	floyd();
	int minv = 0x3f3f3f3f,
		maxv = 0,
		ans;
	for (int i=1; i<=n; ++i){
		maxv = 0;
		for (int j=1; j<=n; ++j)
			if (p[i][j] >= maxv)
				maxv = p[i][j];
		if (maxv < minv){
			minv = maxv; ans = i;
		}
	}
	if (minv == 0x3f3f3f3f){
		cout << 0 << endl;
		return 0;
	}
	cout << ans << " " << minv << endl;
	return 0;
}
