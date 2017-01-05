#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN=505;
struct Node {
    int e,d,t;

    Node(int ee,int dd,int tt):e(ee),d(dd),t(tt) {}

    bool operator < (const Node& a) const {
        if(t!=a.t) {
            return t>a.t;
        }
        return d>a.d;
    }
}cur(0,0,0);

int n,m,s,e,type,t,d,sta,des,tmp;
vector<Node> g[MAXN];
priority_queue<Node> q;
int tim[MAXN],dis[MAXN],pre[MAXN],cnt[MAXN];
int ans_t[MAXN],num_t,ans_d[MAXN],num_d,Time,Distance;

void Dijkstra_t() {
    memset(tim,0x3f,sizeof(tim));
    memset(dis,0x3f,sizeof(dis));
    priority_queue<Node> q;
    q.push(Node(sta,0,0));
    tim[sta]=dis[sta]=0;
    while(!q.empty()) {
        cur=q.top();
        q.pop();
        for(int i=g[cur.e].size()-1;i>=0;--i) {
            e=g[cur.e][i].e;
            d=cur.d+g[cur.e][i].d;
            t=cur.t+g[cur.e][i].t;
            if(t<tim[e]) {
                tim[e]=t;
                dis[e]=d;
                pre[e]=cur.e;
                q.push(Node(e,d,t));
            }
            else if(t==tim[e]&&d<dis[e]) {
                dis[e]=d;
                pre[e]=cur.e;
                q.push(Node(e,d,t));
            }
        }
    }
}

void Dijkstra_d() {
    memset(dis,0x3f,sizeof(dis));
    priority_queue<Node> q;
    q.push(Node(sta,0,0));
    tim[sta]=dis[sta]=0;
    while(!q.empty()) {
        cur=q.top();
        q.pop();
        for(int i=g[cur.e].size()-1;i>=0;--i) {
            e=g[cur.e][i].e;
            d=cur.d+g[cur.e][i].d;
            t=cur.t+1;
            if(d<dis[e]) {
                dis[e]=d;
                cnt[e]=t;
                pre[e]=cur.e;
                q.push(Node(e,d,t));
            }
            else if(d==dis[e]&&t<cnt[e]) {
                cnt[e]=t;
                pre[e]=cur.e;
                q.push(Node(e,d,t));
            }
        }
    }
}

bool isEqual() {
    if(num_t!=num_d)
        return false;
    for(int i=num_t-1;i>=0;--i)
        if(ans_t[i]!=ans_d[i])
            return false;
    return true;
}

int main() {
    while(2==scanf("%d%d",&n,&m)) {
        for(int i=0;i<n;++i)
            g[i].clear();
        while(m-->0) {
            scanf("%d%d%d%d%d",&s,&e,&type,&d,&t);
            g[s].push_back(Node(e,d,t));
            if(type==0)
                g[e].push_back(Node(s,d,t));
        }
        scanf("%d%d",&sta,&des);
        Dijkstra_t();
        tmp=des;
        num_t=0;
        while(tmp!=sta) {
            ans_t[num_t++]=tmp;
            tmp=pre[tmp];
        }
        Time=tim[des];

        Dijkstra_d();
        tmp=des;
        num_d=0;
        while(tmp!=sta) {
            ans_d[num_d++]=tmp;
            tmp=pre[tmp];
        }
        Distance=dis[des];

        if(isEqual()) {
            printf("Time = %d; Distance = %d: %d",Time,Distance,sta);
            while(--num_t>=0)
                printf(" => %d",ans_t[num_t]);
        }
        else {
            printf("Time = %d: %d",Time,sta);
            while(--num_t>=0)
                printf(" => %d",ans_t[num_t]);
            printf("\nDistance = %d: %d",Distance,sta);
            while(--num_d>=0)
                printf(" => %d",ans_d[num_d]);
        }
        printf("\n");
    }
    return 0;
}