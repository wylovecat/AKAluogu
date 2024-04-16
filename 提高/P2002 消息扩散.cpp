#include <iostream>
#include <stack>
#include <vector>
using namespace std;
const int N=1e5+5;
int n,m;
vector<int> G[N];

int dfs_clock,scc_cnt;
int dfn[N],low[N],sccno[N];
stack<int> st;
int in[N];
void tarjan(int u){
    dfn[u]=low[u]=++dfs_clock;
    st.push(u);
    for(auto v:G[u]){
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if(!sccno[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u]){
        int x;
        scc_cnt++;
        do{
            x=st.top();
            st.pop();
            sccno[x]=scc_cnt;
        }while(u!=x);
    }
}

int main( ){
    int u,v;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        G[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    for(int i=1;i<=n;i++){
        for(auto j:G[i]){
            //i->j
            u=sccno[i],v=sccno[j];
            if(u==v) continue;
            in[v]++;
        }
    }
    int ans=0;
    for(int i=1;i<=scc_cnt;i++){
        if(!in[i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}