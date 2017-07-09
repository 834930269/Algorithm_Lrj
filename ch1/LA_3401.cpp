#include<bits/stdc++.h>
using namespace std;
///旋转情况表
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


const int maxn=4;//最大立方体数
///
///立方体数,第i个立方体原始涂色,dfs后得到的答案
///
int n,dice[maxn][6],ans;

///
///借用vector判断改颜色是否已存在,并借第一个立方体的
///涂颜色的顺序(下标)来决定每个颜色的下标是多少.
///进而确定其他立方体的颜色下标
///
vector<string> names;
int ID(const char* name){
    string s(name);
    int n=names.size();
    for(int i=0;i<n;++i)
        if(names[i]==s) return i;//已存在
    names.push_back(s);
    return n;//不存在,加入后返回
}

///每个立方体的旋转方式和旋转后各个面的颜色
int r[maxn],color[maxn][6];

///每次dfs到n个立方体后,判断所需旋转次数
///然后更新ans
void check(){
    ///对于每个立方体按r[i]旋转
    for(int i=0;i<n;++i)
        for(int j=0;j<6;++j) color[i][dice24[r[i]][j]]=dice[i][j];

    int tot=0;///需要重新涂色的面数
    for(int j=0;j<6;++j){///考虑每个面
        int cnt[maxn*6];///每个面颜色出现的次数
        memset(cnt,0,sizeof(cnt));
        int maxface=0;
        ///记录每个面最多的颜色
        for(int i=0;i<n;++i)
            maxface=max(maxface,++cnt[color[i][j]]);
        tot+=n-maxface;///第j面的最少重涂次数
    }
    ans=min(tot,ans);
}

///把每个面都旋转,旋转不计次数,所以直接判断是否旋转后每个面完全相等即可
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
        ans=n*6;///上界,所有面都重涂的结果
        r[0]=0;///第一个立方体不旋转
        dfs(1);
        printf("%d\n",ans);
    }
    return 0;
}
