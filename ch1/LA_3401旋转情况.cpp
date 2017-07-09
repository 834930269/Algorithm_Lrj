#include<bits/stdc++.h>
using namespace std;

int Dleft[]={4,0,2,3,5,1};
int up[]={2,1,5,0,4,3};

//°´ÕÕÅÅÁĞTĞı×ª×ËÌ¬p
void rot(int* T,int* p){
    int q[6];
    memcpy(q,p,sizeof(q));
    for(int i=0;i<6;++i){
        p[i]=T[q[i]];
    }
}

void enumerate_permutations(){
    int p0[6]={0,1,2,3,4,5};
    printf("int dice24[24][6] = {\n");
    for(int i=0;i<6;++i){
        int p[6];
        memcpy(p,p0,sizeof(p0));
        if(i==0) rot(up,p);
        if(i==1) {rot(Dleft,p); rot(up,p);}
        if(i==3) {rot(up,p);rot(up,p);}
        if(i==4) {rot(Dleft,p);rot(Dleft,p);rot(Dleft,p);rot(up,p);}
        if(i==5) {rot(Dleft,p);rot(Dleft,p);rot(up,p);}
        for(int i=0;i<4;++i){
            printf("{%d,%d,%d,%d,%d,%d},\n",p[0],p[1],p[2],p[3],p[4],p[5]);
            rot(Dleft,p);
        }
    }
    printf("};\n");
}

int main(){
    freopen("3401.txt","w",stdout);
    enumerate_permutations();
    return 0;
}
