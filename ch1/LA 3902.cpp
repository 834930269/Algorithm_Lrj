#include<bits/stdc++.h>
using namespace std;

const int maxn=1000+10;
vector<int> gr[maxn],nodes[maxn];
int n,s,k,fa[maxn];
bool covered[maxn];

///无根树转有根树,计算fa数组,根据深度把--叶子节点--插入nodes表中
///u当前节点下标,f,当前节点父节点下标,d深度.
void dfs(int u,int f,int d){
    fa[u]=f;
    int nc=gr[u].size();
    ///距离根节点k距离以内的叶子结点不用记录
    if(nc==1 && d>k) nodes[d].push_back(u);
    for(int i=0;i<nc;++i){
        int v=gr[u][i];
        if(v!=f)dfs(v,u,d+1);
    }
}

void dfs2(int u,int f,int d){
    covered[u]=true;
    int nc=gr[u].size();
    for(int i=0;i<nc;++i){
        int v=gr[u][i];
        if(v!=f&&d<k)dfs2(v,u,d+1);///只覆盖到新服务器不超过k的结点
        ///v!=f => 如果从f访问到u,那么就不能再从u回访f.深搜嘛.一路莽到底.
    }
}

int solve(){
    int ans=0;
    memset(covered,0,sizeof(covered));
    for(int d=n-1;d>k;--d){
        for(int i=0;i<nodes[d].size();++i){
            int u=nodes[d][i];
            if(covered[u])continue;///不考虑已经覆盖的点

            int v=u;
            for(int j=0;j<k;++j)v=fa[v];///找到相邻k级祖先,不可能有-1，因为之前已经把离根k的节点忽略了
            dfs2(v,-1,0);///在结点v设置服务器,然后通过对该服务器深搜
                         ///找到所有的叶子结点
            ans++;
        }
    }
    return ans;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&s,&k);///节点数,初始VOD服务器的编号和k
        for(int i=1;i<=n;++i){gr[i].clear();nodes[i].clear();}
        for(int i=0;i<n-1;++i){
            int a,b;
            scanf("%d%d",&a,&b);
            gr[a].push_back(b);
            gr[b].push_back(a);
        }
        dfs(s,-1,0);
        printf("%d\n",solve());
    }
    return 0;
}
