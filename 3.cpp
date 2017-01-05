#include <cstdio>  
#include <sstream>  
#include <cstring>  
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define  N 1005

int n , m , s ;
vector<int> vt[N] ;
bool cmp(int x ,int y)
{
	return x < y ;
}

bool vis[N] ;
deque<int> que ;
bool flag ;
int outLen ;
void dfs()
{
	int sta = que.back() ;
	if(sta == s && vis[s])
		return ;
	int len = vt[sta].size();
	if(len > 1)
		sort(vt[sta].begin() ,vt[sta].end() , cmp);

	for(int i = 0 ; i < len ;i++)
	{
		int nextNum = vt[sta][i] ;
		if(!vis[nextNum])
		{
			if(!flag)
			{
				printf("%d",sta) ;
				flag = true ;
				outLen ++ ;
			}else{
				printf(" %d",sta) ;
				outLen ++ ;
			}
			que.push_back(nextNum) ;
			vis[sta] = true ;
			dfs() ;
		}
	}
	if(!que.empty())
	{
		int top = que.back() ;
		que.pop_back() ;
		vis[top] = true ;
		if(!flag)
		{
			printf("%d",top) ;
			flag = true ;
			outLen ++ ;
		}else{
			printf(" %d",top) ;
			outLen ++ ;
		}
	}
}

int main()
{
	while( scanf("%d%d%d", &n,&m,&s) != EOF)
	{
		int i ;
		int v1 , v2 ;
		for(i = 1 ; i <= n ; i++)
		{
			vt[i].clear() ;
		}
		for(i = 0 ;i < m ; i++)
		{
			scanf("%d%d" ,  &v1 , &v2);
			vt[v1].push_back(v2) ;
			vt[v2].push_back(v1) ;
		}

		for(i = 1 ; i <= n ; i++)
		{
			vis[i] = false ;
		}
		while(!que.empty())
		{
			que.pop_back();
		}
		que.push_back(s) ;
		flag = false ;
		outLen = 0 ;
		dfs();
		if(outLen != 2*n -1)
			printf(" 0") ;
		printf("\n") ;
	}
	return 0 ;
}