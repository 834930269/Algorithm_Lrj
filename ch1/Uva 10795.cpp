#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL f(int* P,int i,int finaln){
    if(i==0) return 0;
    ///�����ǰ��������ŵ���ʼ���ӵ��������������
    ///�����ƶ�.����f(P,i,final)=f(P,i-1,final)
    if(P[i]==finaln) return f(P,i-1,finaln);
    ///���人ŵ���Ľ���,��ǰi-1�����Ӵ�һ�������ƶ�����һ������
    ///���������Ҫ2^(i-1)-1��.�����ƶ�����i����������
    ///����һ��,һ����Ҫ2^(i-1)��.
    return f(P,i-1,1+2+3-P[i]-finaln)+(1LL<<(i-1));
}

const int maxn=60+10;
int n,start[maxn],finish[maxn];

int main(){
    int kase=0;
    while(scanf("%d",&n)==1&&n){
        for(int i=1;i<=n;++i)scanf("%d",&start[i]);
        for(int i=1;i<=n;++i)scanf("%d",&finish[i]);

        ///����:�����������һ��ʼ�������յ�������
        ///�����ƶ�.
        ///�ҵ����������Ǽ�������Ҫ�ƶ�������.
        int k=n;
        while(k>=1&&start[k]==finish[k])k--;

        ///����:�����ƶ��Ĳ����ǶԳƵ�,�������ƶ��Ĳ���
        ///�Ͳ���������ǰ�ƶ�.
        LL ans=0;
        if(k>=1){
            int other=6-start[k]-finish[k];
            ans=f(start,k-1,other)+f(finish,k-1,other)+1;
        }
        printf("Case %d: %lld\n",++kase,ans);
    }
    return 0;
}
