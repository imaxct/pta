#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <map>
#include <set>
#define LL long long
#define Pr pair<int,int>
using namespace std;
const int INF = 0x3f3f3f3f;
const int msz = 10000;
const int mod = 1e9+7;
const double eps = 1e-8;

struct Point
{
	LL x,y;
};

Point pt[100100];
bool vis[100100];
int s[100100];

bool cal(Point a,Point b,Point c)
{
	return (b.y-a.y)*(c.x-b.x) >= (b.x-a.x)*(c.y-b.y);
}

int main()
{
	int n,x,y;
	scanf("%d",&n);
	int tp = 0;

	memset(vis,0,sizeof(vis));
	for(int i = 0; i < n; ++i)
	{
		scanf("%lld%lld",&pt[i].x,&pt[i].y);

		if(tp >= 1)
		{
			while(tp >= 2 && cal(pt[s[tp-2]],pt[s[tp-1]],pt[i]))
				tp--;
			vis[s[tp-1]] = 1;
		}

		s[tp++] = i;
	}

	int ans = 0;
	for(int i = 1; i < n; ++i) if(vis[i]) ans++;
	printf("%d\n",ans);

	return 0;
}

