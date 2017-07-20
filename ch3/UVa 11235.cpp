#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn=100010;
vector<int> cnt;
int num[maxn],le[maxn],ri[maxn];
int dp[maxn][20];
int N,Q;

void RMQ_init(){
    int n=cnt.size();
    for(int i=0;i<n;++i) dp[i][0]=-cnt[i];
    ///2*(2^(j-1))=2^j
    ///dp(i,j)表示从i开始,长度为2^j的一段元素中的最小值.
    for(int j=1;(1<<j)<=n;++j)
        for(int i=0;i+(1<<j)-1<n;++i)
            dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}

int RMQ(int L,int R){
    if(L>R) return 0;
    int k=0;
    ///如果2^(k+1)<=R-L+1,那么k还可以加一
    while((1<<(k+1)<=R-L+1))k++;
    return min(dp[L][k],dp[R-(1<<k)+1][k]);
}

int main(){
    while(~scanf("%d",&N) && N){
        scanf("%d",&Q);
        cnt.clear();
        int pre=INF,ct=0;
        for(int i=0;i<N;++i){
            int numpy;
            scanf("%d",&numpy);
            if(numpy!=pre){
                pre=numpy;
                ct++;
                num[i]=ct-1;
                le[i]=i;
                if(i>=1)
                    for(int j=le[i-1];j<i;++j)
                        ri[j]=i-1;
                cnt.push_back(1);
            }else{
                num[i]=num[i-1];
                le[i]=le[i-1];
                cnt[ct-1]++;
            }
            if(i==N-1)
                for(int j=le[i];j<=i;++j)
                    ri[j]=i;
        }
/**
        for(int i=0;i<cnt.size();i++)
            cout<<i<<":"<<cnt[i]<<" ";
        cout<<endl;
        for(int i=0;i<N;i++)
            printf("%d(left,right,num):%d %d %d\n",i,le[i],ri[i],num[i]);
**/
        RMQ_init();
        for(int i=0;i<Q;++i){
            int a,b;
            scanf("%d%d",&a,&b);
            if(num[--a]==num[--b])
                printf("%d\n",b-a+1);
            else
                printf("%d\n",max(max((ri[a]-a+1),-RMQ(num[a]+1,num[b]-1)),(b-le[b]+1)));
        }
    }
    return 0;
}
