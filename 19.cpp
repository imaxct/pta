#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std; 
int n, m, k, s;
typedef unsigned long long ull;
map<ull , int>q;
char nm[20];
ull gethash(){
	ull s = 0;
	for (int i=0; i<18; ++i)
		s = (s + (nm[i] - '0' + 1)) * 31;
	return s;
}
int main(){
	cin >> n >> k;
	int t;
	for (int i=0; i<n; ++i){
//		cin >> nm >> t;
		scanf("%s%d", nm, &t);
		ull h = gethash();
		if (t < k)
			q[h]+=k;
		else q[h] += t;
	}
	cin >> m;
	for (int i=0; i<m; ++i){
		//cin >> nm;
		scanf("%s", nm);
		ull h = gethash();
		if (q[h])
			printf("%d\n", q[h]);
		else printf( "No Info\n");
	}
	return 0;
}