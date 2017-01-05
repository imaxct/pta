#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
#define ft first
#define sd second
typedef unsigned long long ull;
const int maxn = 101;
map<ull, int>q[maxn];
int sam[maxn][maxn] = {0};
int sum[maxn] = {0};
int n, m;
char* scan(){
    static char tmp[11];
    int i = 0;
    char c;
    do{
        c = getchar();
        if ('A' <= c && c <= 'Z'){
            if (i < 10) tmp[i++] = c - 'A' + 'a';
        }else if ('a' <= c && c <= 'z'){
            if (i < 10) tmp[i++] = c;
        }else if (c == '#'){
            tmp[i++] = c;
            break;
        }else break;
    }while(1);
    tmp[i] = '\0';
    return tmp;
}
ull getHash(char *str, int len){
    ull res = 0;
    for (int i=0; i<len; ++i){
        res = (res + str[i] - 'a' + 1) * 33;
    }
    return res;
}
int main(){
    memset(sam, 0, sizeof(sam));
    int cnt = 0;
    cin >> n;
    while(n--){
        cnt++;
        bool flag = 1;
        while (flag){
            char *str = scan();
            int len = strlen(str);
            if (len == 1 && str[0] == '#') flag = 0;
            else if (len >= 3){
                ull h = getHash(str, len);
                q[cnt][h]++;
            }
        }
    }
    int a, b;
    cin >> m;
    while (m--){
        cin >> a >> b;
        if (sam[a][b] > 0){
            printf("%.1lf%%\n", sam[a][b]*100.0/(sum[a] + sum[b] - sam[a][b]));
            continue;
        }else{
            int total = 0;
            sum[a] = q[a].size();
            sum[b] = q[b].size();
            for (map<ull, int>::iterator ita = q[a].begin(),itb = q[b].begin();
                    ita!=q[a].end() && itb!=q[b].end();
                ){
                    if (ita->ft == itb->ft){
                        total++; ita++; itb++;
                    }else if (ita->ft < itb->ft){
                        ita++;
                    }else{
                        itb++;
                    }

                }
            sam[a][b] = sam[b][a] = total;
            printf("%.1lf%%\n", total * 100.0 / (sum[a] + sum[b] - total));
        }
    }
	return 0;
}
