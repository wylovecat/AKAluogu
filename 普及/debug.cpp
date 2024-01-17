#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int a[70],n;
bool vis[70];
int m;
int nxt[70];//nxt[x] 长度小于x的下一个小木棍的长度
int les[5000],cnt[5000];
/*
1. 原始木棍的长度 一定是 总长的因子
2. 可能存储相同的小木棍，当长度a[i]不满足要求，和他一样长的小木棍也一定不符合要求
3. 木棍越短，能够拼接的可能性也就越多，可以先从长的小木棍开始拼接，减少整体搜索次数。

4. 如果搜索后发现长度是不合适，且剩余的长度等于原始木棍长度。
说明之前的选择存在问题，可以直接回溯。
5. 如果搜索后发现长度是不合适,且该长度等于剩余的长度

*/
void dfs(int ori,int now,int re,int st){//拼接目标 当前木棍待拼接长度 剩余拼接的
	if(now==0){//一根长木棍拼接成功
		dfs(ori,ori,re-1,1);
		return ;
	}
	if(re==0){//全部拼完
		printf("%d",ori);
		exit(0);
	}
	//剪枝3 寻找时，从大到小去找小木棍
	//找到小木棍中小于等于剩余长度的最大长度
	for(int i=st;i<=m;i++){
		if(!cnt[a[i]] || a[i]>now) continue;
		cnt[a[i]]--;
		dfs(ori,now-a[i],re,i);
		cnt[a[i]]++;
		if(now==ori || a[i]==now) return ;//优化4，5
	}
}
int main(){
	int sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];//求和
		cnt[a[i]]++;//记录a[i]个数
	}
	sort(a+1,a+1+n,greater<int>());//从大到小排序
	m=unique(a+1,a+1+n)-a-1;//用unique 进行去重
	for(int i=a[1];i<=sum;i++){//从最长的小木棍开始找起
		if(sum%i) continue;//长度不是总长的因数不予考虑 可行性优化 //优化1
		dfs(i,i,sum/i,1);
	}
	printf("%d",sum);
	return 0;
}
