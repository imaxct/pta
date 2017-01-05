#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, m;
long long a[1000010];
int main(){
    cin >> n >> m;
	if (n==0 || m == 0)
return 0;
    for (int i=0; i<n; ++i) scanf("%lld", a+i);
    sort(a, a+n);
    for (int j=n-1, i=0; i<m && i < n; ++i, --j){
        printf("%lld%c", a[j], " \n"[(i==m-1)||(i==n-1)]);
    }
    return 0;
}