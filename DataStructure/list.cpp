#include <stdlib.h>
#include <iostream>

typedef int ElemTag;

typedef struct MPNode{
    ElemTag  tag; //1表，2原子
    int exp; // 指数域
    union {
        float coef; //系数域
        struct MPNode *hp; //表结点的表头指针
    };
    struct MPNode *tp; //下一个节点
} * MPList; //m元多项式广义表类型


int main(){
    //P(x,y,z) = (( x10 + 2x6)y3 + 3x5y2)z2 + ((x4 + 6x3)y4 + 2y)z + 15;
    //P = z((A,2),(B,1),(15,0))
    MPList P,P1,P2,P3,A,B;
    P->tag = 1;
    P->exp = 3;
    P->hp = P1;

    P1->tag = 1;
    P1->exp = 2;
    P1->hp  = A;
    P1->tp  = P2;

    P2->tag = 1;
    P2->exp = 1;
    P2->hp  = B;
    P2->tp  = P3;

    P2->tag = 0;
    P2->exp = 0;
    P2->coef  = 15;
}
