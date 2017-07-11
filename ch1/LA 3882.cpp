#include<bits/stdc++.h>
using namespace std;
const int maxn=10000+10;
int f[maxn];
int main(){
    int n,k,m;
    while(scanf("%d%d%d",&n,&k,&m)==3 && n){
        ///最后一次变换只有一个点,所以最终点设为0
        ///每次去掉一个点以后重新编号,所以%i
        ///从底向上的方法
        f[1]=0;
        for(int i=2;i<=n;++i)f[i]=(f[i-1]+k)%i;
        ///因为是从0编号,而题目要求从1编号,所以+1
        ///因为从0开始,而题目要求从m开始删除第k个
        ///所以第一次删除的下标应该是f[n]-k=第一次的起始下标
        ///0-k+m+1=真正的起始坐标,因为第一次需要将m设为0,从m开始重新编号
        int ans=(m-k+1+f[n])%n;
        ///因为m-k+1可能小于0,所以m-k+1+f[n]也可能小于0
        if(ans<=0) ans+=n;
        printf("%d\n",ans);
    }
    return 0;
}
