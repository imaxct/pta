#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
const int maxn=100005;
using namespace std;
int m_father[maxn],m_mother[maxn],m_sex[maxn];
bool vis[maxn],flag;
void dfs(int now,int step,bool model)
{
  if(step==5||!flag)return; 
  if(!model&&now!=-1&&step)vis[now]=true; 
  if(model&&vis[now]&&now!=-1){flag=false;return;}
  int f=m_father[now]; 
  int m=m_mother[now];
  if(now!=-1&&f!=-1)dfs(f,step+1,model);
  if(now!=-1&&m!=-1)dfs(m,step+1,model);
}
int main()
{
  int n,myself,father,mother,q,x,y;
  string sex;
  scanf("%d",&n);
  memset(m_sex,-1,sizeof(m_sex));
  memset(m_father,-1,sizeof(m_father));
  memset(m_mother,-1,sizeof(m_father));
  for(int i=0;i<n;i++)
  {
    cin>>myself>>sex>>father>>mother;
    if(sex=="M")m_sex[myself]=1;
    else if(sex=="F")m_sex[myself]=0;
    m_father[myself]=father;
    m_mother[myself]=mother;
    if(father!=-1){m_sex[father]=1;}
    if(mother!=-1){m_sex[mother]=0;}
  }
  scanf("%d",&q);
  while(q--)
  {
    scanf("%d%d",&x,&y);
    if(m_sex[x]==m_sex[y])printf("Never Mind\n");
    else 
    {
      memset(vis,false,sizeof(vis));
      flag=true;
      dfs(x,0,false);
      dfs(y,0,true);
      if(flag)printf("Yes\n");
      else printf("No\n");
    }
  }
}
