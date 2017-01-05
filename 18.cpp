#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
priority_queue<int>q;
int t, n;
int main(){
	cin >> n;
	for (; n--;) cin >> t, q.push(-t);
	int sum = 0;
	while (q.size()){
		int a = -q.top();
		q.pop();
		if (q.empty()){
			cout << sum << endl;
			return 0;
		}
		int b = -q.top();
		q.pop();
		sum += a + b;
		q.push(-(a+b));
	}
	cout << sum << endl;
	return 0;
}
