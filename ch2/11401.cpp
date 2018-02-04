/*
Link: https://vjudge.net/problem/UVA-11401
type: 组合数学,加法原理,三角形三边定理
题意: 给你N个长度为1~N的杆子,问你能用这N个杆子拼成多少个不同的三角形

题解:
考虑三角形三边定理.
设c(x)为以x为最长边的可拼成三角形的数目.
设y,z为另外两条边.
则 z+y>x => x-y<z 即 x-y<z<x (没有等于号则代表不考虑等边)
考虑y的取值,确定z的取值.
y∈[1,x-1]
当y取1时,z无值.当y取2时,z有唯一值x-1
当y取3时,z可以取(x-1),(x-2).
故y取x-1时,z可以取的种数为x-2种.
根据等差数列求和公式:
总种类数Sn
= 0+1+2+...+(x-2)
= (x-2)(x-1)/2(种)
但这个值并不等于c(x)
因为:
1.对于每个三角形都计数了两遍
=> 因为y=2时 z=x-1,而最后一项为y=x-1,则z一定有一种会取到2
2.以上的计算方式存在y=z的情况
(这种情况下每个特例只会出现一次,因为只有确定y的条件下才可能出现y=z)
=> 比如x=7 y=4时,z就可以取到4
对于第二种问题的解决很简单.
对于每个x考虑y==z的情况:
设t为c(x)中y=z时的情况总数:
则因为当且仅当y∈[(x/2+1),x-1]时存在y=z的可能.
故t=(x-1)-(x/2+1)+1=x-1-(int)x/2
故c(x)=(Sn-t)/2
又因为c(x)是最长边为x时的种类数.
故设f(n)为最长边不超过n时的种类数
根据加法原理,因为互无交集
故 f(n)=c(1)+c(2)+c(3)+...+c(n)
化成递推: f(n)=f(n-1)+c(n)
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10;
long long sum[maxn];
int n;
inline void init(){
    long long Sn,Cn,t;
    memset(sum,0,sizeof(sum));
    for(long long i=4;i<=1000000;++i){
        Sn=(i-2)*(i-1)/2;
        t=i-1-i/2;
        Cn=(Sn-t)>>1;
        int id=(int)i;
        sum[id]=sum[id-1]+Cn;
    }
}
int main(){
    init();
    while(cin>>n){
        if(n<3)break;
        cout<<sum[n]<<endl;
    }
    return 0;
}
