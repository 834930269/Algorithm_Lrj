#include<bits/stdc++.h>
using namespace std;
int N,T,P[1<<17],f[1<<17],cover[1<<17],ca=1;
int main(){
    while(~scanf("%d",&N),N){
        ///初始化第i台计算机的相邻集合
        for(int i=0;i<N;++i){
            int n,m;
            scanf("%d",&n);
            P[i]=1<<i;
            for(int j=0;j<n;++j){
                scanf("%d",&m);
                P[i] |= 1<<m;
            }
        }
        ///S是N个计算机的所有组合的集合,二进制表示,cover[S]是集合的并
        for(int S=0;S<(1<<N);++S){
            cover[S]=0;
            for(int i=0;i<N;++i){
                if(S & (1<<i)) cover[S] |= P[i];///第i台机器选/不选
            }
        }
        f[0]=0;
        int ALL=(1<<N)-1;///全集二进制表示
        for(int S=1;S<(1<<N);++S){
            f[S]=0;
            ///筛出S的子集进行动态规划
            for(int S0=S;S0;S0=(S0-1)&S){
                if(cover[S0]==ALL)///如果子集S的子集的并是全集
                    f[S]=max(f[S],f[S^S0]+1);
            }
        }
        printf("Case %d: %d\n",ca++,f[ALL]);
    }
    return 0;
}
