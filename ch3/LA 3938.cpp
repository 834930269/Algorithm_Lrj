#include<bits/stdc++.h>
using namespace std;
const int maxn=500000+10;
const int maxnode=1000000+10;
typedef long long LL;
typedef pair<int,int> Interval;

LL prefix_sum[maxn];

LL sum(int L,int R){
    return prefix_sum[R]-prefix_sum[L-1];
}

LL sum(Interval A){
    return sum(A.first,A.second);
}

Interval better(Interval A,Interval B){
    if(sum(A)!=sum(B)) return sum(A)>sum(B)?A:B;
    return A<B?A:B;
}

int ql,qr;
struct IntervalTree{
    int max_prefix[maxnode];
    int max_suffix[maxnode];
    Interval max_sub[maxnode];

    void build(int o,int L,int R){
        if(L==R){
            max_prefix[o]=max_suffix[o]=L;
            max_sub[o]=make_pair(L,L);
        }else{
            int M=L+((R-L)>>1);
            int lc=o<<1,rc=o << 1 | 1;
            build(lc,L,M);
            build(rc,M+1,R);

            ///递推max_prefix
            LL v1=sum(L,max_prefix[lc]);
            LL v2=sum(L,max_prefix[rc]);
            if(v1==v2)
                max_prefix[o]=min(max_prefix[lc],max_prefix[rc]);
            else max_prefix[o]=v1>v2?max_prefix[lc]:max_prefix[rc];

            ///递推max_suffix
            v1=sum(max_suffix[lc],R);
            v2=sum(max_suffix[rc],R);
            if(v1==v2)max_suffix[o]=min(max_suffix[lc],max_suffix[rc]);
            else max_suffix[o]=v1>v2?max_suffix[lc]:max_suffix[rc];

            ///递推max_sub
            ///最大序列完全分在中线两边
            max_sub[o]=better(max_sub[lc],max_sub[rc]);
            ///跨越中线
            max_sub[o]=better(max_sub[o],make_pair(max_suffix[lc],max_prefix[rc]));
        }
    }

    Interval query_prefix(int o,int L,int R){
        if(max_prefix[o]<=qr) return make_pair(L,max_prefix[o]);///表示在目标区间范围内
        int M=L+((R-L)>>1);
        int lc=o<<1,rc=o << 1 | 1;
        if(qr<=M) return query_prefix(lc,L,M);
        Interval i=query_prefix(rc,M+1,R);
        i.first=L;
        return better(i, make_pair(L, max_prefix[lc]));
    }

    Interval query_suffix(int o, int L, int R) {
        if(max_suffix[o] >= ql) return make_pair(max_suffix[o], R);
        int M = L + (R-L)/2;
        int lc = o*2, rc = o*2+1;
        if(ql > M) return query_suffix(rc, M+1, R);
        Interval i = query_suffix(lc, L, M);
        i.second = R;
        return better(i, make_pair(max_suffix[rc], R));
    }

    Interval query(int o,int L,int R){
        if(ql<=L&&qr>=R) return max_sub[o];
        int M=L+((R-L)>>1);
        int lc=o<<1,rc=o << 1 | 1;
        ///完全在左区间内
        if(qr<=M) return query(lc,L,M);
        ///完全在右区间内
        if(ql>M) return query(rc,M+1,R);
        ///跨越中线,因为是子区间内的最大值,所以有可能是在这个子区间内跨中线最大
        ///或者中线两边最大
        Interval i1=query_prefix(rc,M+1,R);///右前缀
        Interval i2=query_suffix(lc,L,M);///左后缀
        Interval i3=better(query(rc,M+1,R),query(lc,L,M));///分别左右区间内满足题意的
        return better(i3,make_pair(i2.first,i1.second));///和合并起来的对比
    }
};

IntervalTree tree;

int main(){
    int n,m,val,kase=0;
    while(scanf("%d%d",&n,&m)==2){
        prefix_sum[0]=0;
        for(int i=0;i<n;++i){
            scanf("%d",&val);
            prefix_sum[i+1]=prefix_sum[i]+val;
        }
        tree.build(1,1,n);
        printf("Case %d:\n", ++kase);
        while(m--) {
            int L, R;
            scanf("%d%d", &L, &R);
            ql = L; qr = R;
            Interval ans = tree.query(1, 1, n);
            printf("%d %d\n", ans.first, ans.second);
        }
    }
    return 0;
}
