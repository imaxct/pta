#include<iostream>
using namespace std;
int leave[1005];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        leave[i]=100;
    int temp,cnt=1,flag;
    cin>>temp;
    leave[1]-=temp;
    cout<<temp<<" "<<1<<endl;
    for(int i=2;i<=n;i++){
        flag=1;
        cin>>temp;
        for(int j=1;j<=cnt;j++){
            if(leave[j]>=temp){
                leave[j]-=temp;
                cout<<temp<<" "<<j<<endl;
                flag=0;
                break;
            }
        }
        if(flag){
            cnt++;
            leave[cnt]-=temp;
            cout<<temp<<" "<<cnt<<endl;
        }
    }
    cout<<cnt<<endl;
    return 0;
}