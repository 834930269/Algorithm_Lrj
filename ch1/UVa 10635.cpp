#include<bits/stdc++.h>
using namespace std;
const int maxn=250*250+10;
const int INF=0x3f3f3f3f;
int S[maxn],g[maxn],d[maxn];///LIS����
int num[maxn]; ///num[x]Ϊ����x�ı��,num[x]=0��ʾ��A��δ���ֹ�
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

        ///O(nlog(n))���S[0]��S[n-1]��LIS
        for(int i=1;i<=n;++i){
            g[i]=INF;
        }
        int ans=0;
        for(int i=0;i<n;++i){
            int k=lower_bound(g+1,g+n+1,S[i])-g;///��g[1]~g[n]�в���
            d[i]=k;///k�ǳ���
            g[k]=S[i];///g�����¼����Ϊk��Ŀǰ��ĩ(���)Ԫ�ش�С
            ans=max(ans,d[i]);
        }
        printf("Case %d: %d\n",kase,ans);
    }
    return 0;
}
