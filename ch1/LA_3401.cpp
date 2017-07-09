#include<bits/stdc++.h>
using namespace std;
///��ת�����
int dice24[24][6] = {
{2,1,5,0,4,3},
{2,0,1,4,5,3},
{2,4,0,5,1,3},
{2,5,4,1,0,3},
{4,2,5,0,3,1},
{5,2,1,4,3,0},
{1,2,0,5,3,4},
{0,2,4,1,3,5},
{0,1,2,3,4,5},
{4,0,2,3,5,1},
{5,4,2,3,1,0},
{1,5,2,3,0,4},
{5,1,3,2,4,0},
{1,0,3,2,5,4},
{0,4,3,2,1,5},
{4,5,3,2,0,1},
{1,3,5,0,2,4},
{0,3,1,4,2,5},
{4,3,0,5,2,1},
{5,3,4,1,2,0},
{3,4,5,0,1,2},
{3,5,1,4,0,2},
{3,1,0,5,4,2},
{3,0,4,1,5,2},
};


const int maxn=4;//�����������
///
///��������,��i��������ԭʼͿɫ,dfs��õ��Ĵ�
///
int n,dice[maxn][6],ans;

///
///����vector�жϸ���ɫ�Ƿ��Ѵ���,�����һ���������
///Ϳ��ɫ��˳��(�±�)������ÿ����ɫ���±��Ƕ���.
///����ȷ���������������ɫ�±�
///
vector<string> names;
int ID(const char* name){
    string s(name);
    int n=names.size();
    for(int i=0;i<n;++i)
        if(names[i]==s) return i;//�Ѵ���
    names.push_back(s);
    return n;//������,����󷵻�
}

///ÿ�����������ת��ʽ����ת����������ɫ
int r[maxn],color[maxn][6];

///ÿ��dfs��n���������,�ж�������ת����
///Ȼ�����ans
void check(){
    ///����ÿ�������尴r[i]��ת
    for(int i=0;i<n;++i)
        for(int j=0;j<6;++j) color[i][dice24[r[i]][j]]=dice[i][j];

    int tot=0;///��Ҫ����Ϳɫ������
    for(int j=0;j<6;++j){///����ÿ����
        int cnt[maxn*6];///ÿ������ɫ���ֵĴ���
        memset(cnt,0,sizeof(cnt));
        int maxface=0;
        ///��¼ÿ����������ɫ
        for(int i=0;i<n;++i)
            maxface=max(maxface,++cnt[color[i][j]]);
        tot+=n-maxface;///��j���������Ϳ����
    }
    ans=min(tot,ans);
}

///��ÿ���涼��ת,��ת���ƴ���,����ֱ���ж��Ƿ���ת��ÿ������ȫ��ȼ���
void dfs(int d){
    if(d==n) check();
    else{
        for(int i=0;i<24;++i){
            r[d]=i;
            dfs(d+1);
        }
    }
}

int main(){
    while(scanf("%d",&n)==1&&n){
        names.clear();
        for(int i=0;i<n;++i){
            for(int j=0;j<6;++j){
                char name[30];
                scanf("%s",name);
                dice[i][j]=ID(name);
            }
        }
        ans=n*6;///�Ͻ�,�����涼��Ϳ�Ľ��
        r[0]=0;///��һ�������岻��ת
        dfs(1);
        printf("%d\n",ans);
    }
    return 0;
}