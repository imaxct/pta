#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
string m[10]=  {"0 ","1,.?!",
    "2ABC","3DEF",
    "4GHI", "5JKL", "6MNO",
    "7PQRS", "8TUV", "9WXYZ"};
char s[500];
int main(){
	while (~scanf("%s", s)){
    	printf("%c", m[s[0]-'0'][(strlen(s)-1)%m[s[0]-'0'].length()]);
	}
    return 0;
}
