#include <bits/stdc++.h>
using namespace std;
queue<int> q;
int main()
{
	int n,op,x;
	cin>>n;
	while(n--){
		cin>>op;
		if(op==1){
			cin>>x;
			q.push(x);
		}else if(op==2){
			if(q.empty()){
				cout<<"ERR_CANNOT_POP\n";
			}else{
				q.pop();
			}
		}else if(op==3){
			if(q.empty()){
				cout<<"ERR_CANNOT_QUERY\n";
			}else{
				cout<<q.front()<<endl;
			}
		}else{
			cout<<q.size()<<endl;
		}
	}
	return 0;
}
