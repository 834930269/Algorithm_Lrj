#include<bits/stdc++.h>
using namespace std;
int T,n,m,vis[2000][2],d[2000][2];
vector<int> Graph[1010];

int dp(int i,int j,int f){
    if(vis[i][j]) return d[i][j];
    vis[i][j]=1;
    int& ans=d[i][j];

    ans=2000;
    for(int k=0;k<Graph[i].size();++k)
        if(Graph[i][k]!=f)
            ans+=dp(Graph[i][k],1,i);
    if(!j && f>=0)  ans++;

    if(j || f<0){
        int sum=0;
        for(int k=0;k<Graph[i].size();++k)
            if(Graph[i][k]!=f)
                sum+=dp(Graph[i][k],0,i);
        if(f>=0) sum++;
        ans=min(ans,sum);
    }
    return ans;
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i) Graph[i].clear();
        for(int i=0;i<m;++i){
            int x,y;
            scanf("%d%d",&x,&y);
            Graph[x].push_back(y);
            Graph[y].push_back(x);
        }
        memset(vis,0,sizeof(vis));
        int ans=0;
        for(int i=0;i<n;++i){
            if(!vis[i][0])///ÐÂµÄÒ»¿ÃÊ÷
                ans+=dp(i,0,-1);
        }
        printf("%d %d %d\n",ans/2000,m-ans%2000,ans%2000);
    }
    return 0;
}
