#include <iostream>
#include <vector>
using namespace std;
const int N=1e5+5;
int n;
int siz[N],in[N];
vector<int> G[N];
void dfs(int u,int f)
{
    int sum=1;
    for(auto v:G[u]){
        if(v==f) continue;
        dfs(v,u);
        if(in[v]==1) sum++;
        siz[u]+=siz[v];
    }
    siz[u]+=sum/2;
}
int main()
{
    int u,v;
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
        in[u]++;in[v]++;
    }
    dfs(1,1);
    cout<<siz[1];
    return 0;
}