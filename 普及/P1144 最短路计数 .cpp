#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
const int M=100003;
vector<int> G[N];
int n,m;
int step[N];
bool vis[N];
ll ans[N];
void bfs(int st){
	memset(step,0x3f,sizeof(step));//最少到达的步数
	queue<int> q;
	q.push(st);
	ans[st]=1;
	step[st]=0;
	vis[st]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		
		//遍历u的邻接点v且到v的步数不能更长
		for(auto v:G[u]){
			if(step[v]<step[u]+1) continue;
			ans[v]=(ans[v]+ans[u])%M;
			step[v]=step[u]+1;
			if(!vis[v]){
				vis[v]=1;
				q.push(v);	
			}
		}
	}
	
}
int main()
{
	int x,y;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	bfs(1);
	for(int i=1;i<=n;i++){
		printf("%lld\n",ans[i]);
	}
	
	
	return 0;
}
