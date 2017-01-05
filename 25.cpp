#include <cstdio>
#include <cstring>
#include <climits>
#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define INF 0x3f3f3f3f
#define pb push_back
#define fst first
#define scd second
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&(-x))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int maxn = 1000;
int d[maxn + 10], n, input[maxn + 10];
bool vis[maxn + 10];
void print(){
	for (int i=0; i<n; ++i)
		printf("%d", d[i]);
	printf("\n");
}
void dfs(int now, int tot){
	if (tot >= n){
		print();
		return;
	}
	
	for (int i = 1 ; i<=n; ++i){
		if (!vis[i]){
			d[tot] = input[i];
			vis[i] = 1;
			dfs(i + 1, tot + 1);
			vis[i] = 0;
		}
	}
}

int main(){
	memset(vis, 0, sizeof(vis));
	cin >> n;
	if (n > maxn){
		cout << "error params\n";
		return -1;
	}
	for (int i=1; i<=n; ++i)
		input[i] = i;
	dfs(0, 0);
	return 0;
}