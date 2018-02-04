/*
Link: https://vjudge.net/problem/UVA-11538
type: 组合数学,乘法/加法原理,以及初中数学n^2和=n(n+1)(2n+1)/6

题意: 有N×M大小的棋盘,问,给你两个皇后,使他们可以互相攻击对方的可能有多少种.

题解: 分为三个方向,第一个方向为同一行,第二个方向为同一列,第三个方向为同一斜线

同一行: 对于白皇后有nm种取法,每种取法中黑皇后有(m-1)种取法,所以结果是nm(m-1)
同一列: 合同一行类似,结果是nm(n-1)
同一斜线: 画图观察,假设n<=m,(n>m可以不用看,因为等价于n<=m转置)
    可以观测到所有'/'方向的斜线长度为: 1,2,3,...,n,n,n,n-1,n-2...,2,1
    其中n的个数 = 总条数-2×(n-1) = m+n-1-2n+2 = m-n+1(m>n时反过来即可)
    其中每条斜线上的取法种数 = i*(i-1)
    diagonal=Sigma(1~n-1) i(i-1)   =>   i==1时确实是0种可能,因为皇后是放在块内而不是点上的.
    则   All_diagonal = 2(2*diagonal+(m-n+1)*n*(n-1))  => 这里的乘2是因为有两种斜线'/'和'\'的可能
    其中diagonal=Sigma(1~n-1) i^2 - Sigma(1~n-1) i  =>n方和展开公式,等差数列求和
                =n(n-1)(2n-1)/6 - n(n-1)/2
                =n(n-1)(2n-4)/6

        All_diagonal = 2(2*(n(n-1)(2n-4)/6)+(m-n+1)*n*(n-1))
                     = 2n(n-1)(3m-n-1)/3

这三种情况互不相交,最终答案就等于三者和.
*/

//Code
#include<bits/stdc++.h>
using namespace std;
unsigned long long N,M;
int main(){
    while(cin>>N>>M){
        if(N==0&&M==0)break;
        unsigned long long row=N*M*(M-1);
        unsigned long long column=N*M*(N-1);

        if(N>M) swap(N,M);
        cout<<row+column+2*N*(N-1)*(3*M-N-1)/3<<endl;
    }
    return 0;
}
