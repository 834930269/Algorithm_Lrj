#include<bits/stdc++.h>
using namespace std;
const int maxn=250*250+10;
const int INF=0x3f3f3f3f;
int S[maxn],g[maxn],d[maxn];///LIS所需
int num[maxn]; ///num[x]为整数x的编号,num[x]=0表示在A中未出现过
int main(){
    int T;
    scanf("%d",&T);
    for(int kase=1;kase<=T;++kase){
        int N,p,q,x;
        scanf("%d%d%d",&N,&p,&q);
        fill(num,num+maxn,0);
        for(int i=1;i<=p+1;++i){
            scanf("%d",&x);
            num[x]=i;
        }
        int n=0;
        for(int i=0;i<q+1;++i){
            scanf("%d",&x);
            if(num[x]) S[n++]=num[x];
        }

        ///O(nlog(n))求解S[0]到S[n-1]的LIS
        for(int i=1;i<=n;++i){
            g[i]=INF;
        }
        int ans=0;
        for(int i=0;i<n;++i){
            int k=lower_bound(g+1,g+n+1,S[i])-g;///在g[1]~g[n]中查找
            d[i]=k;///k是长度
            g[k]=S[i];///g数组记录长度为k的目前最末(最大)元素大小
            ans=max(ans,d[i]);
        }
        printf("Case %d: %d\n",kase,ans);
    }
    return 0;
}
