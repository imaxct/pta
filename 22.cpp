#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 5010;
int list[maxn * 4], n, m, k, p, top = 0;
void insert(int x){
	if (x > 1 && list[x] < list[x / 2]){
		swap(list[x / 2], list[x]);
		insert(x / 2);
	}
}
int main(){
	cin >> n >> m;
	for (int i=1; i<=n; ++i) {
		cin >> p;
		list[++top] = p;
		insert(top);
	}
	for (int i=1; i<=m; ++i){
		cin >> k;
		while (k){
			printf("%d%c", list[k], " \n"[k==1]);
			k/=2;
		}
	}
	return 0;
}
