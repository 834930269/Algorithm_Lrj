#include<bits/stdc++.h>
using namespace std;
const int maxn=100+20;
int A[maxn],vis[maxn][maxn],S[maxn],d[maxn][maxn];

int dp(int b,int e){
    if(vis[b][e]) return d[b][e];///���仯����
    vis[b][e]=1;
    int m=0;
    ///��b->eѡ��С�Ľ��,Ȼ��d[b][e]ѡsum(b,e)-m
    for(int k=b+1;k<=e;++k) m=min(m,dp(k,e));
    ///��e->bѡ��С�Ľ��,Ȼ��d[b][e]ѡsum(b,e)-m
    for(int k=b;k<e;++k) m=min(m,dp(b,k));
    d[b][e]=S[e]-S[b-1]-m;
    return d[b][e];
}

int main(){
    int n;S[0]=0;
    while(~scanf("%d",&n) && n){
        for(int i=1;i<=n;++i){
            scanf("%d",&A[i]);
            S[i]=S[i-1]+A[i];
        }
        memset(vis,0,sizeof(vis));
        printf("%d\n",2*dp(1,n)-S[n]);///=>dp(1,n)-(S[n]-dp(1,n))
    }
    return 0;
}
