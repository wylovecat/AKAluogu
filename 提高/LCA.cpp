#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
vector<int> G[N];
struct node {
    int v, id;
};
/*
以一种顺序访问所有的点，先访问的点在数据结构上操作，
后访问的点查询数据结构。
Tarjan的LCA（最近公共祖先）算法是一种基于后序DFS（深度优先搜索）和并查集的离线算法。这种算法的目的是找出给定节点集合中的节点对的最近公共祖先。

以下是该算法的基本理解和步骤：

1. 初始化：
首先，将树上所有节点的父亲节点设置为它们自身。这意味着每个节点最初都被视为一个独立的集合，其祖先就是它自己。
2.DFS遍历：
从根节点开始，递归地搜索所有的子树。在搜索的过程中，处理与当前根节点相关的所有查询。
3.集合合并：
当搜索到一个节点x时，创建一个只包含x本身的集合。然后，递归地搜索x的所有子节点。
当一个子节点搜索完毕后，将子节点的集合与x节点的集合合并，并将合并后的集合的祖先设置为x。
这意味着这棵子树内的所有节点与x的LCA都是x。
4.查询处理：
当所有子树都被处理后，处理与当前根节点x相关的查询。
对于x的每一个查询，如果查询的另一个节点v已经访问过（即已经在某个集合中），那么x和v的LCA就是v所在集合的祖先。
5.并查集优化：
并查集用于高效地合并集合和查找集合的祖先。
在DFS的过程中，每当两个节点被合并到一个集合时，它们的祖先就被更新为这两个节点的LCA。
这样，在后续的查询中，我们可以直接通过查找节点的祖先来得到LCA，而不需要重新遍历整棵树。

总的来说，Tarjan的LCA算法通过DFS和并查集的结合，实现了高效的离线LCA查询。
它首先将树上的节点划分为多个集合，每个集合的祖先都是相同的。
然后，通过合并集合和更新祖先，逐步缩小查询范围，最终得到节点对的LCA。

*/
vector<node> query[N];
int n, m, s;
int fa[N], ans[N];
bool vis[N];
int findRt(int x)
{
    if (x == fa[x]) return x;
    return fa[x] = findRt(fa[x]);
}
void tarjan(int u)
{
    vis[u] = 1;//标记u被访问
    for (auto v : G[u]) {//遍历u的邻接点
        if (!vis[v]) {//未访问
            tarjan(v);//继续搜索
            fa[v] = u;//合并并查集 将y合并到父结点u上
        }
    }
    //查询所有与u有查询关系的y
    for (auto e : query[u]) {
        int v = e.v, id = e.id;
        if (vis[v]) {//y被访问过
            ans[id] = findRt(v);//LCA就为findRt(y)
        }
    }
}
int main()
{
    int x, y;
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1;i < n;i++) {
        scanf("%d%d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for (int i = 1;i <= n;i++) {
        fa[i] = i;
    }
    for (int i = 1;i <= m;i++) {
        scanf("%d%d", &x, &y);
        query[x].push_back(node{ y,i });
        query[y].push_back(node{ x,i });
    }
    tarjan(s);
    for (int i = 1;i <= m;i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}