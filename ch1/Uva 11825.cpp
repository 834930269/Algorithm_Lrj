#include<bits/stdc++.h>
using namespace std;
int N,T,P[1<<17],f[1<<17],cover[1<<17],ca=1;
int main(){
    while(~scanf("%d",&N),N){
        ///��ʼ����į����������ڼ���
        for(int i=0;i<N;++i){
            int n,m;
            scanf("%d",&n);
            P[i]=1<<i;
            for(int j=0;j<n;++j){
                scanf("%d",&m);
                P[i] |= 1<<m;
            }
        }
        ///S��N���������������ϵļ���,�����Ʊ�ʾ,cover[S]�Ǽ��ϵĲ�
        for(int S=0;S<(1<<N);++S){
            cover[S]=0;
            for(int i=0;i<N;++i){
                if(S & (1<<i)) cover[S] |= P[i];///��į����ѡ/��ѡ
            }
        }
        f[0]=0;
        int ALL=(1<<N)-1;///ȫ�������Ʊ�ʾ
        for(int S=1;S<(1<<N);++S){
            f[S]=0;
            ///ɸ��S���Ӽ����ж�̬�滮
            for(int S0=S;S0;S0=(S0-1)&S){
                if(cover[S0]==ALL)///����Ӽ�S���Ӽ��Ĳ���ȫ��
                    f[S]=max(f[S],f[S^S0]+1);
            }
        }
        printf("Case %d: %d\n",ca++,f[ALL]);
    }
    return 0;
}
