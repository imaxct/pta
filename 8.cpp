#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
struct node{
	int t, p;
};
int main() {
	int n;
	cin >> n;
	queue <node> q;
	for(int i = 0; i < n; i++) {
		node tmp;
		scanf("%d%d", &tmp.t, &tmp.p);
		if(tmp.p > 60) tmp.p = 60;
		q.push(tmp);
	}
	int k;
	cin >> k;
	int win[15] = {0}, num[15] = {0};
	int wait = 0, maxn = 0, sum = 0;
	while(!q.empty()) {
		int flag = 0;
		int minn = 0x3f3f3f3f, imin = 0;
		for(int i = 0; i < k; i++) {
			if(win[i] < q.front().t) {
				win[i] = q.front().t + q.front().p;
				num[i]++;
				flag = 1;
				q.pop();
				break;
			}
			if(minn > win[i]) {
				minn = win[i];
				imin = i;
			}
		}
		if(flag == 0) {
			wait = win[imin] - q.front().t;
			win[imin] += q.front().p;
			if(maxn < wait) maxn = wait;
			sum += wait;
			num[imin]++;
			q.pop();
		}
	}
	int last = win[0];
	for(int i = 0; i < k; i++) {
		if(win[i] > last) last = win[i];
	}
	printf("%.1lf %d %d\n", sum * 1.0 / n * 1.0, maxn, last);
	for(int i = 0; i < k; i++)
		printf("%d%c", num[i], " \n"[i==k-1]);
	return 0;
}