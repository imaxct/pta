#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
char ma[21][21];
int cnt[21][21];
int n, m;
const int fx[] = {0,1,0,-1};
const int fy[] = {1,0,-1,0};
int check(int x, int y){
	int sum = 0;
	if (cnt[x][y]==2 || cnt[x][y]==1){
		sum++;
		cnt[x][y] = -1;
	}
	for (int i=0; i<4; ++i){
		int tx = x + fx[i],
			ty = y + fy[i];
		if (0<=tx&&tx<n&&0<=ty&&ty<m){
			if (cnt[tx][ty]==2) cnt[tx][ty] = 1;
			else if (cnt[tx][ty]==1){
				cnt[tx][ty] = -1;
				sum++;
			}
		}
	}
	return sum;
}
int main(){
    cin >> n >> m;
    for (int i=0; i<n; ++i){
    	scanf("%s", ma[i]);
        for (int j=0; j<m; j++)
            if (ma[i][j]=='#')
                cnt[i][j] = 2;
			else cnt[i][j] = -1;
    }
    int k, x, y, sum = 0;
    cin >> k;
    for (int i=0; i<k; ++i){
		cin >> x >> y;
		cout << check(x, y) << endl; 
	}
    return 0;
}