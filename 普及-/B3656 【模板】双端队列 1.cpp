#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
list<int> q[N];
char s[20];
int main()
{
	int n,a,x;
	scanf("%d",&n);
	while(n--){
		scanf("%s",s);
		scanf("%d",&a);
		if(strcmp(s,"push_back")==0){
			scanf("%d",&x);
			q[a].push_back(x);
		}else if(strcmp(s,"pop_back")==0){
			if(!q[a].empty()){
				q[a].pop_back();	
			} 
		}else if(strcmp(s,"push_front")==0){
			scanf("%d",&x);
			q[a].push_front(x);
		}else if(strcmp(s,"pop_front")==0){
			if(!q[a].empty()){
				q[a].pop_front();
			} 
		}else if(strcmp(s,"size")==0){
			printf("%d\n",(int)q[a].size());
		}else if(strcmp(s,"front")==0){
			if(!q[a].empty()) printf("%d\n",q[a].front());
		}else if(strcmp(s,"back")==0){
			if(!q[a].empty()) printf("%d\n",q[a].back());
		}
	}
	return 0;
}
