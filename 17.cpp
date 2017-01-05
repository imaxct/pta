#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
vector<string>last(103);
unordered_map<string,string>pa;
const string nil("nil");

int main(){
  int n,m;cin>>n>>m;cin.get();
  while(n--){
    string s;getline(cin,s);
    int cnt=count(s.begin(),s.end(),' ');
    if(!cnt){
      pa[s]=nil;
      last[0]=s;
    }else{
      s=s.substr(cnt);
      pa[s]=last[cnt/2-1];
      last[cnt/2]=s;
    }   //else
  }     //while
  const char *T="True",*F="False";
  while(m--){
    string a,b,c,d;
    cin>>a>>d>>d>>b>>d>>c;
    switch(b[0]){
    case 'p': swap(a,c);
    case 'c': cout<<(pa[a]==c?T:F)<<endl;
      break;
    case 's': cout<<(pa[a]==pa[c]?T:F)<<endl;
      break;
    case 'a': swap(a,c);
    case 'd': while(pa[a]!=c&&pa[a]!=nil)a=pa[a];
	cout<<(pa[a]==nil?F:T)<<endl;
    } //switch
  }   //while
  return 0;
}
