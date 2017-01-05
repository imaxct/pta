#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1010;
const int maxm = 3010;
int n, m;
int fa[maxn];
int deg[maxn];
int getfa(int x){
	return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
void merge(int x, int y){
	int fx = getfa(x), fy = getfa(y);
	if (fx != fy)
		fa[y] = fx;
}
bool isfa(int x, int y){
	return getfa(x)==getfa(y);
}
void init(){
	cin >> n >> m;
	int x, y;
	for (int i=1; i<=n; ++i) fa[i]=i;
	for (int i=0; i<m; ++i)
		scanf("%d%d", &x, &y), merge(x, y), ++deg[x], ++deg[y];
}
int main(){
	init();
	for (int i=1; i<=n; ++i)
		if (deg[i]%2!=0 || !isfa(1, i)){
			cout << 0 << endl;
			return 0;
		}
	cout << 1 << endl;
	return 0;
}
