#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL f(int* P,int i,int finaln){
    if(i==0) return 0;
    ///如果当前最大的这个号的起始盘子等于最终落脚盘子
    ///不用移动.所以f(P,i,final)=f(P,i-1,final)
    if(P[i]==finaln) return f(P,i-1,finaln);
    ///经典汉诺塔的结论,将前i-1个盘子从一个柱子移动到另一个柱子
    ///这个步骤需要2^(i-1)-1步.加上移动盘子i到最终盘子
    ///的那一步,一共需要2^(i-1)步.
    return f(P,i-1,1+2+3-P[i]-finaln)+(1LL<<(i-1));
}

const int maxn=60+10;
int n,start[maxn],finish[maxn];

int main(){
    int kase=0;
    while(scanf("%d",&n)==1&&n){
        for(int i=1;i<=n;++i)scanf("%d",&start[i]);
        for(int i=1;i<=n;++i)scanf("%d",&finish[i]);

        ///结论:如果最大的盘子一开始就在最终的柱子上
        ///则不用移动.
        ///找到号码最大的那几个不需要移动的盘子.
        int k=n;
        while(k>=1&&start[k]==finish[k])k--;

        ///结论:由于移动的步数是对称的,即往回移动的步伐
        ///和步数等于往前移动.
        LL ans=0;
        if(k>=1){
            int other=6-start[k]-finish[k];
            ans=f(start,k-1,other)+f(finish,k-1,other)+1;
        }
        printf("Case %d: %lld\n",++kase,ans);
    }
    return 0;
}
