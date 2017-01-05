#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int r, n;
double a[10];
int main(){
	cin >> r;
	while (r--){
	cin >> n;
	for (int i=0; i<n; ++i) cin >> a[i];
	sort(a, a+n);
	double sum = 0;
	for (int i=1; i<n-1; ++i){
		sum += a[i];
	}
	printf("score:%.2lf\n", sum/(1.0*n-2));
	}
	return 0;
}